#include <iostream>

using namespace std;
//
//class Date {
//public:
//	Date(int year, int month, int day)
//		:_month(month),
//		_year(year),
//		_day(day)
//	{
//	}
//	Date& operate(const Date& d)
//	{
//		if (this != &d)
//		{
//			_month = d._month;
//			_day = d._day;
//			_year = d._year;
//		}
//		return *this;
//	}
//private:
//	int _month;
//	int _year;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	//Date d2(d1);
//	return 0;
//}

//class MyClass {
//public:
//    //MyClass() {  // 显式定义默认构造函数
//    //    // 默认构造逻辑
//    //}
//
//    MyClass(const MyClass& other) {  // 显式定义拷贝构造函数
//        // 拷贝构造逻辑
//    }
//};
//
//int main() {
//    MyClass obj1; // 正确：使用默认构造函数
//    MyClass obj2 = obj1; // 正确：使用拷贝构造函数
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}

//class Test {
//public:
//	void func()
//	{
//		cout << "hehe" << endl;
//	}
//	int* a;
//};




//class Date {
//	friend ostream& operator<<(ostream& out, const Date& d);
//public:
//	Date(int year, int month, int day)
//		:_month(month),
//		_year(year),
//		_day(day)
//	{
//	}
//	Date& operate(const Date& d)
//	{
//		if (this != &d)
//		{
//			_month = d._month;
//			_day = d._day;
//			_year = d._year;
//		}
//		return *this;
//	}
//private:
//	int _month;
//	int _year;
//	int _day;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << "年/月/日" << ':' << d._year << '/' << d._month << '/' << d._day << endl;
//	return out;
//}
//int main()
//{
//	//Test t1;
//	//void (Test::*p)() = &Test::func;
//	//(t1.*p)();
//	//
//	Date d1(2024, 10, 5),d2(2003,9,10);
//	cout << d1 << d2 << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class B;  // 前向声明
//
//class A {
//// 声明B为A的友元类
//private:
//    static int _privateStaticVar;
//    static void _privateStaticFunc() {
//        cout << "A's private static function" << endl;
//    }
//public:
//    class B {
//    public:
//        void accessA() {
//            // 友元类可以访问A的私有静态成员变量和函数
//            cout << "Accessing A's private static variable: " << _privateStaticVar << endl;
//            _privateStaticFunc();
//        }
//    };
//};
//
//// 定义静态成员变量
//int A::_privateStaticVar = 100;
//


//int main() {
//    A::B b;
//    b.accessA();  // B类可以访问A类的私有静态成员
//    return 0;
//}

//
//inline int add(int a, int b)
//{
//	return a + b;
//}

//#include <iostream>
//
//using namespace std;
//
//class Widget {
//public:
//	Widget() {}
//	Widget(const Widget& w)
//	{
//		cout << "拷贝构造" << endl;
//	}
//};
//
//Widget f(Widget u)
//
//{
//
//	Widget v(u);
//
//	Widget w = v;
//
//	return w;
//
//}
//
//int main() {
//
//	Widget x;
//
//	Widget y = f(f(x));
//
//}
//void* operator new(size_t sz,const char* buffer)
//{
//	void* p = malloc(sz);
//	if (p == nullptr)
//		return nullptr;
//	cout << buffer << endl;
//	return p;
//}
//void operator delete(void* p,const char* buffer)
//{
//	free(p);
//	cout << buffer << endl;
//}
//int main()
//{
//	int* pt = new("这是自己的new") int[3];
//	operator delete((void*)pt,"这是自己的delete");
//	return 0;
//}

//int add(int a, int b)
//{
//	cout << "不是模板函数";
//	return a + b;
//}
//
//template <typename T>
//T add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout << add(1, 2) << endl;
//	return 0;
//}

class MyClass {
protected:
    typedef int MyInt;  // 仅在 MyClass 和其派生类中可访问
};

class Derived : public MyClass {
public:
    void func() {
        MyInt value = 20;  // 合法
    }
};

int main() {
     MyClass::MyInt value;  // 不合法，无法访问
    return 0;
}


