#include <iostream>

using namespace std;

class A

{

public:

    virtual void f()

    {

        cout << "A::f()" << endl;

    }

};



class B : public A

{

private:

    virtual void f()

    {

        cout << "B::f()" << endl;

    }

};


int main() {

    A* pa = (A*)new B;

    pa->f();
    B* pb = new B;
    pb->f();
    return 0;
}