#include <iostream>
#include <cstdio>
#include <Windows.h>
using namespace std;

int main()
{
	double cost, revenue;
	cout << "����cost revenue��";
	cin >> cost >> revenue;
	printf("�ۿۣ�%.2lf", cost / (revenue * 0.87));
	Sleep(5000);
	return 0;
}