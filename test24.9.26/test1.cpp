#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10;

int n;
bool st[N][N];
void dfs(int x)
{
	if (x > (n%2 == 0 ? n-1 : n)) return;
	cout << "µÚ" << x << "Ìì£º" << endl;
	bool oneday[N];
	memset(oneday, 0, sizeof oneday);
	for (int i = 1; i <= n; i++)
	{
		if (oneday[i]) continue;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (st[i][j]) continue;
			if (oneday[j] || oneday[i]) continue;
			oneday[i] = oneday[j] = true;
			st[i][j] = st[j][i] = true;
			cout << i << "v" << j << endl;
		}
		
	}
	dfs(x + 1);
}
int main()
{
	cin >> n;
	dfs(1);
	return 0;
}