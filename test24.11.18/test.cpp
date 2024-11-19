#include <iostream>
#include <cstdio>

using namespace std;


//double da = 1.1;
//int b = static_cast<double>(da);
//
//double db = static_cast<int>(b);
//double dc = 1;
//cout << dc << endl;
//int a = 1;
//double* p = reinterpret_cast<double*>(a);
//cout << &a << "  " << p << endl;
//volatile const int a = 1000;
//volatile const int* pa = &a;
//int* pb = const_cast<int*>(pa);
//*pb = 2000;
//cout << a << endl;

class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A * pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	//B* pb = static_cast<B*>(&a);

	return 0;
}