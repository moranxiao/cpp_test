#include <mutex>
#include <thread>
#include <iostream>
namespace moran {
	template<class T>
	struct DeleteOne {
		void operator()(T* ptr)
		{
			delete ptr;
		}
	};

	template <class T, class D = DeleteOne<T>>
	class shared_ptr {
	private:
		void Release()
		{
			bool flag = false;
			_pMtx->lock();
			if (--(*_pCount) == 0)
			{
				//定制删除
				if (_ptr)
				{
					D()(_ptr);
					std::cout << "delete" << std::endl;
				}

				delete _pCount;
				flag = true;
			}
			_pMtx->unlock();
			//锁不能在上锁期间析构，不然会出现错误
			if (flag)
			{
				delete _pMtx;
			}

		}
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr),
			_pCount(new size_t(1)),
			_pMtx(new std::mutex)
		{}

		shared_ptr(const shared_ptr& other)
			:_ptr(other._ptr),
			_pCount(other._pCount),
			_pMtx(other._pMtx)
		{
			_pMtx->lock();
			(*_pCount)++;
			_pMtx->unlock();
		}

		shared_ptr& operator=(const shared_ptr& other)
		{
			if (other._ptr != _ptr)
			{
				Release();
				_ptr = other._ptr;
				_pCount = other._pCount;
				_pMtx = other._pMtx;

				_pMtx->lock();
				(*_pCount)++;
				_pMtx->unlock();
			}
			return *this;
		}
		int use_count()
		{
			return *_pCount;
		}
		~shared_ptr()
		{
			Release();
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		size_t* _pCount;
		std::mutex* _pMtx;
	};

	template <class T>
	class weak_ptr {
	public:
		weak_ptr(const shared_ptr<T>& spt)
			:_ptr(spt.get())
		{}
		weak_ptr(const weak_ptr& wpt)
			:_ptr(wpt._ptr)
		{}
		weak_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}

		weak_ptr& operator=(const weak_ptr& wpt)
		{
			_ptr = wpt._ptr;
			return *this;
		}
		weak_ptr& operator=(const shared_ptr<T>& spt)
		{
			_ptr = spt.get();
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}

using namespace std;

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode() { cout << "~ListNode()" << endl; }
};
int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}