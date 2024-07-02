#include "stack.h"

stack::stack()
{
        base = new char[10];
        top = base;
}
stack::~stack()
{
    delete[] base;
}

void stack::clearstack()        //清空
{
    top = base;
}

int stack::isempty()            //判空
{
    if (top == base)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int stack::length()            //求长度
{
    return top - base;
}
char stack::gettop()            //取栈顶元素
{
    if (length() == 0)
    {
        return 0;
    }
    else
    {
        return *(top - 1);
    }
}
int stack::push(char c)            //进栈
{
    if (length() == 10)
    {
        std::cout << "this stack is full!" << std::endl;
        return 0;
    }
    *top = c;
    top++;
    return 1;
}
int stack::pop(char* c)            //出栈
{
    if (length() == 0)
    {
        std::cout << "This stack is empty！" << std::endl;
        return 0;
    }
    *c = *--top;
    return 1;
}
void stack::traverse()        //遍历
{
    char* p;
    for (p = top - 1; p > base; p--)
    {
        std::cout << *p << "->";
    }
    std::cout << *p << std::endl;
}