#include <iostream>

using namespace std;

class Widget {
public:
	Widget(){}
	Widget(const Widget& w)
	{
		cout << "拷贝构造" << endl;
	}
};

﻿Widget f(Widget u)

{

	Widget v(u);

	Widget w = v;

	return w;

}

int main() {

	Widget x;

	Widget y = f(f(x));

}