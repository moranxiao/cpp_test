#include <iostream>

using namespace std;

class BaseClass
{
public:
	virtual	void fn1()
	{
		cout << "BaseClass::fn1 " << endl;
	}
	void fn2()
	{
		cout << "BaseClass::fn2" << endl;
	}
};
class DerivedClass:public BaseClass
{
public:
	void fn1()
	{
		cout << "DerivedClass::fn1" << endl;
	}
	void fn2()
	{
		cout << "DerviedClass::fn2" << endl;
	}
};



int main()
{
	BaseClass* pb = new DerivedClass;
	DerivedClass* pd = new DerivedClass;
	pb->fn1(); //构成多态，派生类函数重写基类fn1()，所以执行派生类的fn1()
	pb->fn2(); //fn2不是虚函数，不构成多态，由于是基类指针，所以调用基类的fn2()
	
	pd->fn1(); //派生类指针指向派生类对象，不构成多态，执行派生类的fn1()
	pd->fn2(); //派生类指针指向派生类对象，不构成多态，执行派生类fn2()


}