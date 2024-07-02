#include <iostream>
using namespace std;

template<class T,size_t N>
class SortedSet //升序
{
public:
	SortedSet()
		:_size(0)
	{}
	bool insert(T value)
	{
		if (_size == 0) //没有元素，可直接插入
		{
			_arr[++_size] = value;
			return true;
		}
		int index = find(value);
		if (_arr[index] == value || _size == N - 1) //有相同元素或者空间达到上限，不可插入
			return false;
		else if (_arr[index] < value) //如果所有元素都比value小，直接在末尾插入
		{
			_arr[++_size] = value;
		}
		else //如果找到了最小的大于value的元素，则将大于value的元素后移一位，给value腾出位置
		{
			for (int i = _size; i >= index; i--)
			{
				_arr[i + 1] = _arr[i];
			}
			_arr[index] = value;
			_size++;
		}
		return true;
	}
	int getAddress(T value)
	{
		//没有元素返回0
		if (_size == 0) return 0; 
		int index = find(value);
		if (index < _size) // 如果找到的下标不是最后一个元素，说明找到的要么等于value，要么是最小的大于value的元素
		{
			if (_arr[index] == value)
				return index + 1;
			else
				return index;
		}
		else
		{
			//如果找到的下标是最后一个元素，当最后一个元素都小于或等于value时，说明没有大于value的元素了
			if (_arr[index] <= value) return 0;
			else
				return index;
		}
	}
	bool delElement(T value)
	{
		//如果没有元素返回false
		if (_size == 0) return false;
		int index = find(value);
		if (_arr[index] != value) //找不到等于value元素
			return false;
		for (int i = index; i < _size; i++)
		{
			_arr[i] = _arr[i + 1];
		}
		_size--;
		return true;
	}
	void print()
	{
		for (int i = 1; i <= _size; i++)
		{
			cout << _arr[i] << ' ';
		}
		cout << endl;
	}
private:
	//寻找值为value的下标，如果所有元素都小于value,则返回的是最大的元素的下标，如果有元素大于value，但是没有等于value的元素，则返回最小的大于value的元素
	int find(T value) 
	{
		int l = 1, r = _size;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (_arr[mid] < value) l = mid + 1;
			else r = mid;
		}
		return r;
	}
private:
	T _arr[N]; //元素从下标1处开始存储，因为getAddress失败要返回0
	size_t _size;
};

int main()
{
	SortedSet<int, 100> s;
	s.insert(1);
	s.insert(10);
	s.insert(11);
	s.insert(20);
	s.insert(9);
	s.print();
	s.insert(7);
	s.insert(9);
	s.insert(8);
	s.insert(17);
	s.insert(31);
	s.insert(44);
	s.print();

	s.delElement(44);
	s.delElement(18);
	s.print();
	cout << s.getAddress(17) << endl;
	cout << s.getAddress(30) << endl;
	cout << s.getAddress(33) << endl;
	cout << s.getAddress(1) << endl;


	return 0;
}


