//背包问题求具体方案
#include <iostream>

using namespace std;

const int N = 1e3+10;

int dp[N][N],v[N],w[N];
int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i+1][j];
            if(j >= v[i])
                dp[i][j] = max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    int t = m;
    for(int i = 1; i <= n; i++)
    {
        if(t >= v[i] && dp[i][t] == dp[i+1][t-v[i]]+w[i]) 
        {
            cout << i << ' ';
            t -= v[i];
        }
    }
    return 0;
}