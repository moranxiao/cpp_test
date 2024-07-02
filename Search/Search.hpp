#include <iostream>

int HalfSearch(int q[], int sz, int x)
{
	int l = 0, r = sz - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (q[mid] < x) l = mid + 1;
		else r = mid;
	}
	if (q[r] == x)
		return r;
	else
		return -1;
}

