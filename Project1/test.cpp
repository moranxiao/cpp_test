#include <iostream>

using namespace std;

//class A{
//public:
//	int _num;
//};
//
//class B :public A{
//public:
//	int _num;
//};

//int main()
//{
	//B b;
	//b._num = 1;
	//b.A::_num = 2;
	//cout << b._num << b.A::_num;
	//int i = 1;
	//const double& d = i;
	//int i = 0;
	//const double* d = &1.1;
//	return 0;
//}s

class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student {
protected:
	string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

