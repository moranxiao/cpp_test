#include <iostream>

using namespace std;


class BaseClass
{
public:
	virtual ~BaseClass()
	{
		cout << "BaseClass 析构函数" << endl;
	}
};
class DerivedClass :public BaseClass
{
public:
	~DerivedClass()
	{
		cout << "DerivedClass 析构函数" << endl;
	}
};


int main()
{
	BaseClass* p = new DerivedClass;
	delete p;
	//输出：DerivedClass 析构函数
	//      BaseClass 析构函数
	//原因：析构函数会给改名为destruction,由于基类将析构改为了虚函数，delete p基类指针指向派生类对象，符合多态的条件
	//所以实际调用DerivedClass的析构函数：先析构自己，再调用基类析构函数
}