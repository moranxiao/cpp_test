#include <iostream>
#include <fstream>

using namespace std;

const int N = 25;

bool st[N][N];//存储已被监管的地方
bool g[N][N]; //存储有机器人的地方
int n;
size_t minCount = -1;

void GetMinCount(int x,int y,size_t count)
{
	if (x > n && y > n)
	{
		minCount = min(count, minCount);
		return;
	}
	if (st[x][y])
	{
		
	}
	//
}

void test()
{
	GetMinCount();

}


int main()
{
	test();
	return 0;
}