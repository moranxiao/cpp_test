#include <iostream>

class array2{
public:
    array2(size_t row = 10,size_t col = 10);
    int*& operator[](int index);
    bool operator()(int index);
    ~array2();
private:
    int** _array;
    size_t _row_size;
    size_t _col_size;
};
