#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;

int OptDecompose()
{
	if (n <= 4) return n;
	vector<int> nums;
	int t = 2;
	while (1)
	{
		n -= t;
		nums.push_back(t++);
		if (n <= nums.back())
		{
			if (n == nums.back())
			{
				nums[nums.size() - 1]++;
				n--;
			}
			int k = nums.size() - 1;
			while (n)
			{
				nums[k--]++;
				n--;
			}
			break;
		}
	}
	int res = 1;
	for (auto e : nums)
		res *= e;
	return res;
}

int main()
{
	ifstream in("input.txt");
	if (!in.is_open()) exit(1);
	in >> n;
	
	int res = OptDecompose();

	ofstream out("output.txt");
	if (!out.is_open()) exit(2);
	out << res;
	return 0;
}