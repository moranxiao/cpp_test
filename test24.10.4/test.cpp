#include <iostream>

using namespace std;

//class A
//{
//public:
//	void Print()
//	{
//		cout << "hehe" << endl;
//	}
//};
//void Func(int a = 10)
//{
//	cout << "void Func(int a = 10)" << endl;
//}
//void Func(int a)
//{
//	cout << "void Func(int a)" << endl;
////}
//
//void test1(int array[])
//{
//	for (auto e : array)
//		cout << e << endl;
//	
//}
//
//int main()
//{
//	////A* a = nullptr;
//	//a->Print();
//	int array[5] = { 1,2,3,4,5 };
//	test1(array);
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}