#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;
//
//
//int main()
//{
//	char str[] = "abcdefghijklmn";
//	strcpy(str + 3, str);
//	cout << str;
//	return 0;
//}

int main()
{
	//void* ptr = malloc(10);
	void* ptr = new int;
	free(ptr);
	return 0;
}

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int n = nums.size();
			int l = 0,r = n-1;
			for(int i = 0; i <= r; i++)
			{
				if(nums[i] == 0) swap(nums[l++],nums[i]);
				else if(nums[i] == 2) swap(nums[r--],nums[i--]);
			}
		}
	};