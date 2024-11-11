#include <iostream>
#include <fstream>

using namespace std;

const int N = 25;

bool st[N][N];//存储已被监管的地方
bool g[N][N]; //存储有机器人的地方
bool min_g[N][N];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int n,m;
size_t minCount = -1;

void GetMinCount(int x,int y,size_t count)
{
	if (x >= n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!st[i][j]) return;
		if (count < minCount)
		{
			minCount = count;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					min_g[i][j] = g[i][j];
		}
		return;
	}
	//1.不在这放机器人
	GetMinCount(x + (y+1) / m, (y + 1) % m, count);
	if(!st[x][y])//此点没有被监视
	{
		//2.在这放机器人

		//将周围的点标记为已被监视
		for (int i = 0; i < 4; i++) 
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			//如果碰到已被监视的点，则表示此情况不行，回溯前要先消除影响
			if (st[tx][ty])
			{
				for (int j = 0; j < i; j++)
				{
					int kx = x + dx[j], ky = y + dy[j];
					if (kx < 0 || kx >= n || ky < 0 || ky >= m) continue;
					st[kx][ky] = false;
				}
				return;
			}
			st[tx][ty] = true;
		}
		st[x][y] = true;
		g[x][y] = true;
		GetMinCount(x + (y + 1) / m, (y + 1) % m, count+1);
		//消除影响
		st[x][y] = false;
		g[x][y] = false;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			st[tx][ty] = false;
		}
	}
	//
}

void test2()
{
	ifstream input("input.txt");
	if (!input.is_open())
	{
		cout << "未能打开input.txt" << endl;
		exit(1);
	}
	input >> n >> m;
	input.close();
	GetMinCount(0,0,0);
	
	ofstream output("output.txt");
	if (!output.is_open())
	{
		cout << "未能打开output.txt" << endl;
		exit(2);
	}
	output << minCount << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			output << min_g[i][j] << ' ';
		output << endl;
	}
}


int main()
{
	test2();
	return 0;
}