#include <iostream>
#include "vector.h"
//using namespace std;

//template <class T1,typename T2>
//void func(T1 a, T2 b)
//{
//	cout << "func(" << typeid(a).name() << " a," << typeid(b).name() << " b)" << endl;
//}
//
//int main()
//{
//	func(1, 2.1);
//	return 0;
//
// }
using namespace std;
class Person{
public:
	virtual void func()
	{
		cout << "I am a person" << endl;
	}
	char name[20];
	size_t age;
};

class Student:public Person {
public:
	virtual void func() override
	{
		cout << "I am a student" << endl;
	}
};

int g_num = 100;
int main()
{
	Student s;
	const char* str = "hello world";
	int num = 10;
	int* p1 = new int(10);
	cout << "��������" << (void*)str << endl;
	cout << "��̬����" << &g_num << endl;
	cout << "������" << p1 << endl;
	cout << "ջ����" << &num << endl;
	cout << "���ָ�룺" << (void*)*(int*)&s << endl;
}
