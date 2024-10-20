#pragma
#include <assert.h>

// 声明
namespace moran
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*sz);
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i]; // T对象是自定义类型时，调用T对象operator=
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x);
		iterator insert(iterator pos, const T& x);
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}