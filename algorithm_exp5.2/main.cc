#include <iostream>
#include <fstream>

using namespace std;

const int N = 25;

bool st[N][N];//�洢�ѱ���ܵĵط�
bool g[N][N]; //�洢�л����˵ĵط�
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