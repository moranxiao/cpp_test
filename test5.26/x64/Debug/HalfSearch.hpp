#include <iostream>


//’€∞Î≤È’“
int HalfSearch(int q[],int sz,int x)
{
	int l = 0, r = sz - 1;
	int cnt = 0;
	while (l <= r)
	{
		cnt++;
		int mid = l + r >> 1;
		if (x > q[mid]) l = mid + 1;
		else if (x < q[mid])
			r = mid - 1;
		if (q[mid] == x)
			break;
	}
	return cnt;
}




