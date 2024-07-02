#include <iostream>


using namespace std;

class A
{
public:
	virtual void func1() {};
};

class B :public A
{
public:
	virtual void func1() {};
	virtual void func2() {};
};

int main()
{
	A a;
	B b;
	return 0;
}