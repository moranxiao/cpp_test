#include <iostream>

using namespace std;


class BaseClass
{
public:
	virtual ~BaseClass()
	{
		cout << "BaseClass ��������" << endl;
	}
};
class DerivedClass :public BaseClass
{
public:
	~DerivedClass()
	{
		cout << "DerivedClass ��������" << endl;
	}
};


int main()
{
	BaseClass* p = new DerivedClass;
	delete p;
	//�����DerivedClass ��������
	//      BaseClass ��������
	//ԭ�����������������Ϊdestruction,���ڻ��ཫ������Ϊ���麯����delete p����ָ��ָ����������󣬷��϶�̬������
	//����ʵ�ʵ���DerivedClass�������������������Լ����ٵ��û�����������
}