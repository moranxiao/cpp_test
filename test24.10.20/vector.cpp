#include "vector.h"

namespace moran
{

	template<class T>
	void vector<T>::push_back(const T& x)
	{
		insert(_finish, x);
	}

	template<class T>
	typename vector<T>::iterator vector<T>::insert(typename vector<T>::iterator pos, const T& x)
	{
		assert(pos >= _start);
		assert(pos <= _finish);

		if (_finish == _end_of_storage)
		{
			size_t len = pos - _start;
			reserve(capacity() == 0 ? 4 : capacity() * 2);
			pos = _start + len;
		}

		// Ų
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}
		*pos = x;

		++_finish;

		return pos;
	}
}