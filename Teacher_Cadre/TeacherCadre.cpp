#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

class Teacher 
{
public:
	Teacher(const char* name, size_t age, const char* sex, const char* address, const char* tele, const char* title);
	void display();
protected:
	char _name[10];
	size_t _age;
	char _sex[5];
	char _address[40];
	char _tele[15];
	char _title[20];
};
Teacher::Teacher(const char* name, size_t age, const char* sex, const char* address, const char* tele, const char* title)
:_age(age)
{
	strncpy(_name, name, sizeof(_name));
	strncpy(_sex, sex, sizeof(_sex));
	strncpy(_address, address, sizeof(_address));
	strncpy(_tele, tele, sizeof(_tele));
	strncpy(_title, title, sizeof(_title));
}

void Teacher::display()
{
	cout << "Name:" << _name << endl;
	cout << "Age:" << _age << endl;
	cout << "Sex:" << _sex << endl;
	cout << "Address:" << _address << endl;
	cout << "Tele:" << _tele << endl;
}



class Cadre
{
public:
	Cadre(const char* name, size_t age, const char* sex, const char* address, const char* tele, const char* post);
	void display();
protected:
	char _name[10];
	size_t _age;
	char _sex[5];
	char _address[40];
	char _tele[15];
	char _post[20];
};

Cadre::Cadre(const char* name, size_t age, const char* sex, const char* address, const char* tele, const char* post)
	:_age(age)
{
	strncpy(_name, name, sizeof(_name));
	strncpy(_sex, sex, sizeof(_sex));
	strncpy(_address, address, sizeof(_address));
	strncpy(_tele, tele, sizeof(_tele));
	strncpy(_post, post, sizeof(_post));
}
void Cadre::display()
{
	cout << "Name:" << _name << endl;
	cout << "Age:" << _age << endl;
	cout << "Sex:" << _sex << endl;
	cout << "Address:" << _address << endl;
	cout << "Tele:" << _tele << endl;
}

class Teacher_Cadre : public Teacher,public Cadre	
{
public:
	Teacher_Cadre(const char* name, size_t age, const char* sex, const char* address, \
		const char* tele, const char* title, const char* post, size_t wages);

	void show();
protected:
	size_t _wages;
};

Teacher_Cadre::Teacher_Cadre(const char* name, size_t age, const char* sex, \
	const char* address, const char* tele, const char* title, const char* post, size_t wages)
	:Teacher(name, age, sex, address, tele, title),
	Cadre(name, age, sex, address, tele, post),
	_wages(wages)
{}

void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "Title:"  << Teacher::_title << endl;
	cout << "Post:"  << Cadre::_post << endl;
	cout << "Wages:" << _wages << endl;
}


int main()
{
	Teacher_Cadre tc("小王", 18, "男","湖北大学","1313131313", "主管","高级工程师", 10000);
	tc.show();
	return 0;
}