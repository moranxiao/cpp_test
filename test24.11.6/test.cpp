#include <iostream>
#include <string>
#include <functional>


using namespace std;

//void ShowList()
//{
//	cout << "结束咯" << endl;
//}
//
//template <class T,class ...Args>
//void ShowList(const T& value, Args... args)
//{
//	cout << value << ", 还有" << sizeof...(args) << "个参数包" << endl;
//	ShowList(args...);
//}

//template <class T>
//void printArgs(const T& value)
//{
//	cout << value << endl;
//}
//
//template < class ...Args>
//void ShowList(Args... args)
//{
//	int a[] = { (printArgs(args),0)... };
//}


struct Test {

	double plusd(double x, double y)
	{
		return x + y;
	}
	static int plusi(int x, int y)
	{
		return x + y;
	}
};

int mul(int a, int b, int ratio)
{
	return a * b + ratio;
}

int main()
{
	//ShowList(1, "hehe", 1.1);
	function<double(Test,double, double)> func1 = &Test::plusd;
	cout << func1(Test(),1.1 , 2.2) << endl;

	auto newcall = bind(mul, placeholders::_1, 2,placeholders::_2);
	cout << newcall(2,4) << endl;
	return 0;
}