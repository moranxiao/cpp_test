#include "array2.h"


array2::array2(size_t row,size_t col)
{
    _array = new int*[row];
    for(int i = 0; i < row; i++)
        _array[i] = new int[col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            _array[i][j] = i*col+j;
    _row_size = row;
    _col_size = col;
}
int*& array2::operator[](int index)
{
    if(operator()(index))
    {
        return _array[index];
    }
    else{
        std::cout << "越界访问" << std::endl;
        exit(1);
    }
}
bool array2::operator()(int index)
{
    if(index >= 0 && index < _row_size)
        return true;
    return false;
}
array2::~array2()
{
    for(int i = 0; i < _row_size; i++)
        delete[] _array[i];
    delete[] _array;
}


