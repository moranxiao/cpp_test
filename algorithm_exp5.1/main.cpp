#include <iostream>
#include <fstream>
using namespace std;

const int N = 25;

int c[N][N]; //c[i][j]第j个人干第i个工作的花费
bool st[N]; //st[i]第i份工作是否被选
int n;  //总共有多少个工作
size_t mincost = -1; //最小花费

void GetMinCost(int u,size_t cost)
{
	//如果每个人都分配完了，就更新mincost；
	if (u > n)
	{
		mincost = min(mincost,cost);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (st[i]) continue;
		st[i] = true;
		GetMinCost(u + 1, cost + c[i][u]);
		st[i] = false;
	}
}

void test1()
{
	ifstream ifile("input.txt");
	
	ifile >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			ifile >> c[i][j];
	}
	ifile.close();
	GetMinCost(1, 0);

	ofstream ofile("output.txt");
	ofile << mincost << endl;
	ofile.close();
}


int main()
{
	test1();
	return 0;
}