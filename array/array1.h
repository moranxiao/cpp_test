#include <iostream>

class array1
{
public:
    array1(size_t n = 10);
    int& operator[](int index);
    bool operator()(int index);
    ~array1();
private:
    int* _array;
    size_t _size;
};
