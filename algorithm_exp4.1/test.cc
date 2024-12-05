#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

int n;
vector<int> length;

template <class Compare>
int GetExtreme()
{
	Compare cmp;
	priority_queue<int, vector<int>, Compare> heap;
	for (int i = 0; i < length.size(); i++)
	{
		heap.push(length[i]);
	}
	int res = 0;
	while (heap.size() != 1)
	{
		int x = heap.top(); heap.pop();
		int y = heap.top(); heap.pop();
		res += x + y - 1;
		heap.push(x + y);
	}
	return res;
}
int main()
{
	ifstream in("input.txt");
	if (!in.is_open())
		exit(1);
	in >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		in >> x;
		length.push_back(x);
	}

	ofstream out("output.txt");
	if (!out.is_open()) exit(2);

	out << GetExtreme<less<int>>() << ' ' << GetExtreme<greater<int>>();
	in.close();
	out.close();
	return 0;
}