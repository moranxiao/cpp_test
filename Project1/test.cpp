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
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};
class Graduate : public Student {
protected:
	string _seminarCourse; // �о���Ŀ
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

