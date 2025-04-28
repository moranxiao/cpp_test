#include <iostream>
using namespace std;

class BaseA {
public:
    BaseA(char a, int b);
    ~BaseA();
    virtual void show() {};
protected:
    char m_a;
    int m_b;
};
BaseA::BaseA(char a, int b) : m_a(a), m_b(b) {
    cout << "BaseA constructor" << endl;
}
BaseA::~BaseA() {
    cout << "BaseA destructor" << endl;
}

class BaseB {
public:
    BaseB(char c, int d);
    ~BaseB();
    virtual void show() {};
protected:
    char m_c;
    int m_d;
};
BaseB::BaseB(char c, int d) : m_c(c), m_d(d) {
    cout << "BaseB constructor" << endl;
}
BaseB::~BaseB() {
    cout << "BaseB destructor" << endl;
}

class Derived : public BaseA, public BaseB {
public:
    Derived(char a, int b, char c, int d);
    ~Derived();
public:
    virtual void show();
};
Derived::Derived(char a, int b, char c, int d) : BaseA(a, b), BaseB(c, d) {
    cout << "Derived constructor" << endl;
}
Derived::~Derived() {
    cout << "Derived destructor" << endl;
}
void Derived::show() {
    cout << m_a << ", " << m_b << ", " << m_c << ", " << m_d << endl;
}

int main() {
    Derived obj(1, 2, 3, 4);
    obj.show();
    cout << sizeof(Derived) << endl;
    return 0;
}