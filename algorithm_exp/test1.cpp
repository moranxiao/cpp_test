#include <iostream>
#include <fstream>

using namespace std;

const int N = 30;

int p[N][N], q[N][N];
bool st[N];
int n;
int res;

void dfs(int u,int value)
{
	if (u > n)
	{
		res = max(res, value);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (st[i]) continue;
		st[i] = true;
		dfs(u + 1, value + p[u][i] * q[i][u]);
		st[i] = false;
	}
}

int main()
{
	ifstream in("input.txt");
	if (!in.is_open()) exit(1);
	in >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			in >> p[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			in >> q[i][j];
		}
	}
	dfs(1,0);

	ofstream out("output.txt");
	if (!out.is_open()) exit(2);
	out << res;

	in.close();
	out.close();
	return 0;
}