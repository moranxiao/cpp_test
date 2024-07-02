#include <iostream>

class A
{
public:
	A(int aa)
		:a(aa)
	{}
protected:
	int a;
};

class B : virtual public A
{
public:
	B(int aa,int bb):
		A(aa),
		b(bb)
	{}
protected:
	int b;
};

class C : virtual public A
{
public:
	C(int aa, int cc)
		:A(aa),
		c(cc)
	{}
protected:
	int c;
};

class D : public B, public C
{
public:
	D(int aa,int bb,int cc,int dd)
		:A(aa),
		B(aa,bb),
		C(aa,cc),
		d(dd)
	{}
protected:
	int d;
};
using namespace std;

int main()
{
	//在32位下，指针是4字节
	cout << sizeof(A) << endl; //4 
	cout << sizeof(B) << endl; // 12
	cout << sizeof(C) << endl; // 12
	cout << sizeof(D) << endl; // 24
		
	D objd(1, 2, 3, 4);
	int* p = (int*)&objd;
	cout << "p[0]:" << p[0] << endl;
	cout << "*((int*)p[0] + 1):" << *((int*)p[0] + 1) << endl;
	cout << "p[1]:" <<  p[1] << endl;
	cout << "p[2]:" << p[2] << endl;
	cout << "*((int*)p[2] + 1):" << *((int*)p[2]+1) << endl;
	cout << "p[3]:" << p[3] << endl;
	cout << "p[4]:" << p[4] << endl;
	cout << "p[5]:" << p[5] << endl;


	return 0;
}