#include <iostream>
#include <fstream>
using namespace std;

const int N = 25;

int c[N][N]; //c[i][j]��j���˸ɵ�i�������Ļ���
bool st[N]; //st[i]��i�ݹ����Ƿ�ѡ
int n;  //�ܹ��ж��ٸ�����
size_t mincost = -1; //��С����

void GetMinCost(int u,size_t cost)
{
	//���ÿ���˶��������ˣ��͸���mincost��
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