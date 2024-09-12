#include <iostream>

using namespace std;

void MergeToSort(int* a, int l, int r, int k)
{
	for (int i = l; i < k; i++)
	{
		if (a[i] <= a[k]);
		else
		{
			int x = a[k];
			for (int j = k; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = x;
			k++;
		}
	}
}
int main()
{
	int a[] = { 4,8,11,19,21,2,7,9,13,17,31 };
	MergeToSort(a, 0, sizeof(a) / sizeof(int) - 1, 5);
	for (auto e : a)
	{
		cout << e << ' ';
	}
	return 0;
}