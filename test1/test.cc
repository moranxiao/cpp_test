#include <iostream>

class array1{
public:
    array1(size_t n = 10)
    {
        _size = n;
        _array = new int[n];
        for(int i = 0; i < n; i++)
        {
            _array[i] = i;
        }
    }
    int& operator[](int index)
    {
        if((*this)(index))
            return _array[index];
        else
        {
            std::cout << "越界访问"  << std::endl;
            exit(1);
        }    
    }
    bool operator()(int index)
    {
        if(index >=0 && index < _size)
            return true;
        return false;
    }   
    ~array1()
    {
        delete[] _array;
    }
private:
    int* _array;
    size_t _size;
};

class array2{
public:
    array2(size_t row = 10,size_t col = 10)
    {
        _array = (array1*)operator new (row*sizeof(array1));
        for(int i = 0; i < row; i++)
            _array[i] = array1(col);
        _col_size = col;
        _row_size = row;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                _array[i][j] = i*col + j;
            }
        }
    }
    array1& operator[](int index)
    {
        if((*this)(index))
        {
            return _array[index];
        }
        else{
            std::cout << "越界访问" << std::endl;
            exit(1);
        }
    }
    bool operator()(int index)
    {
        if(index >= 0 && index < _row_size)
            return true;
        return false;
    }
    ~array2()
    {
        delete[] _array;
    }
private:
    array1* _array;
    size_t _row_size;
    size_t _col_size;
};
using namespace std;

int main()
{
    array2 arr(15,15);
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
            cout << arr[i][j] << ' ';
       cout << endl;
    }

    return 0;
}