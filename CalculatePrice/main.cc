#include <iostream>
#include <cstdio>
#include <Windows.h>
using namespace std;

int main()
{
	double cost, revenue;
	cout << " ‰»Îcost revenue£∫";
	cin >> cost >> revenue;
	printf("’€ø€£∫%.2lf", cost / (revenue * 0.87));
	Sleep(5000);
	return 0;
}