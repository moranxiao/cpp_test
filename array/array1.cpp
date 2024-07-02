#include "array1.h"

array1::array1(size_t n)
{
    _size = n;
    _array = new int[n];
    for(int i = 0; i < n; i++)
    {
        _array[i] = i;
    }
}
int& array1::operator[](int index)
{
    if((*this)(index))
        return _array[index];
    else
    {
        std::cout << "越界访问"  << std::endl;
        exit(1);
    }    
}
bool array1::operator()(int index)
{
    if(index >=0 && index < _size)
        return true;
    return false;
}
array1::~array1()
{
    delete[] _array;
}