#include <iostream>

using namespace std;

// int func(int a = 10)
// {
//     return a;
// }

// int func(int a)
// {
//     return a;
// }

// int main()
// {
//     std::cout << func(1);
//     return 0;
// }
// typedef char* pstring;
// int main()
// {
//     // char arr[] = "hello";
//     // const pstring  p1 = arr;
//     // p1[1] = ' ';
//     // cout << p1; 
//     //  pstring* const p2 = nullptr;
//     // char* const * p = nullptr;
//     // p2 = p;
//     // cout << typeid(p1).name() << endl << typeid(p2).name()<< endl;
//     // p1 = p2;
//     // p2 = p1;
//     char * *  a = nullptr;
//     char arr[] = "hello";
//     char* parr[2] = {arr,nullptr};
//     a = parr;
//     a[1] = arr;
//     a[0][2] = ' ';
//     return 0;
// }

// class A
// {
// public:
// void Print()
// {
// cout << "Print()" << endl;
// }
// private:
// int _a;};
// int main()
// {
// A* p = nullptr;
// p->Print();
// return 0;
// }

// class A
// {
// public:
// void PrintA()
// {
// cout<<_a<<endl;
// }
// private:
// int _a;
// };
// int main()
// {
// A* p = nullptr;
// p->PrintA();
// return 0;
// }

// class Time
// {
// public:
// Time(int i)
// {
// cout << "Time()" << endl;
// _hour = 0;
// _minute = 0;
// _second = 0;
// }
// private:
// int _hour;
// int _minute;
// int _second;
// };
// class Date
// {
// public:
//     Date(int i)
//     :_t(i)
//     {}
// private:
// // 基本类型(内置类型)
// int _year;
// int _month;
// int _day;
// // 自定义类型
// Time _t;
// };
// int main()
// {Date d;
// return 0;
// }

class A
{
public:
A(int a)
:_a1(a)
,_a2(_a1)
{}
void Print() {
cout<<_a1<<" "<<_a2<<endl;
}
private:
int _a2;
int _a1;
};
int main() {
A aa(1);
aa.Print();
}