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
	pb->fn1(); //���ɶ�̬�������ຯ����д����fn1()������ִ���������fn1()
	pb->fn2(); //fn2�����麯���������ɶ�̬�������ǻ���ָ�룬���Ե��û����fn2()
	
	pd->fn1(); //������ָ��ָ����������󣬲����ɶ�̬��ִ���������fn1()
	pd->fn2(); //������ָ��ָ����������󣬲����ɶ�̬��ִ��������fn2()


}