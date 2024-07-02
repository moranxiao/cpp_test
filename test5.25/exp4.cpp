#include <iostream>

using namespace std;

class A
{
public:
	virtual void f1()
	{
		cout << "f1 of A is called" << endl;
	}
	virtual void f2()
	{
		cout << "f2 of A is called" << endl;
	}
	virtual void f3()
	{
		cout << "f3 of A is called" << endl;
	}
};

class B : public A
{
public:
	virtual void f1()
	{
		cout << "f1 of B is called" << endl;
	}
	virtual void f2()
	{
		cout << "f2 of B is called" << endl;
	}
};


typedef void (*FUNCP)();

// 不能在64位下这样操作，因为int*在64位下是8字节，而解引用后为int，转换时会发生错误，可以用size_t*。
//void display(B b, int cnt)
//{
//	int* p = (int*)&b;
//	for (int i = 0; i < cnt; i++)
//	{
//		((FUNCP) * ((int*)*p + i))();
//	}
//}
void display(B b, int cnt)
{
	size_t* p = (size_t*)&b;
	for (int i = 0; i < cnt; i++)
	{
		((FUNCP) * ((size_t*)*p + i))();
	}
}


int main()
{
	B b;
	int cnt = 3;
	display(b, cnt);
	return 0;
}