#include <iostream>

using namespace std;

int BinarySearchMax(int* a, int l, int r,int value)
{
	if (l >= r) return l;
	int mid = l + r + 1>> 1;
	if (a[mid] > value) return BinarySearchMax(a, l, mid - 1, value);
	else return BinarySearchMax(a, mid, r, value);
}
int BinarySearchMin(int* a, int l, int r, int value)
{
	if (l >= r) return l;
	int mid = l + r >> 1;
	if (a[mid] >= value) return BinarySearchMin(a, l, mid, value);
	else return BinarySearchMin(a, mid + 1, r, value);
}
int main()
{
	int a[] = { 1,3,5,7,9,11,13,15,17,19 };
	int max = BinarySearchMax(a, 0, sizeof(a)/sizeof(int) - 1, 6);
	int min = BinarySearchMin(a, 0, sizeof(a) / sizeof(int) - 1,6);
	cout << "��x������ʱ��С��x�����Ԫ���±꣺" <<max << endl  
		<<   "��x������ʱ������x����СԪ���±꣺" << min << endl;
	return 0;
}