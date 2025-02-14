#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 410;

int dp[N][N];
int n,m;

int main()
{
    cin >> n >> m;
    memset(dp,0x3f,sizeof dp);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dp[a][b] = dp[b][a] = min(dp[a][b],c);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) dp[i][i] = 0;
            else
            dp[i][j] = dp[i][j];
        }
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        res = max(res,dp[1][i]);
    }
    if(res == 0x3f3f3f3f) cout << -1;
    else  cout << res << endl;
    return 0;
}