#include <iostream>

class Count{
public:
    Count()
    :_count(0)
    {}
    size_t operator++(int)
    {
        return _count++;
    }
    size_t operator++()
    {
        return ++_count;
    }
    size_t operator--(int)
    {
        return _count--;
    }
    size_t operator--()
    {
        return --_count;
    }
    void reset()
    {
        _count = 0;
    }
    void set(int x)
    {
        _count = x;
    }
    size_t get()
    {
        return _count;
    }
private:
    size_t _count;
};