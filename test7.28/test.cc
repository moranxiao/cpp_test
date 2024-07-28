//宠物小精灵之收服
#include <iostream>
using namespace std;

const int N = 1e3+10;

pair<int,int> dp[N][N];

int n,m,k;

int main()
{
    cin >> n >> m >> k;
    int res = 0;
    for(int i = 0; i < k; i++)
    {
        int v,w;
        cin >> v >> w;
        for(int j = n; j >= v; j--)
        {
            for(int t = m; t > w; t--)
            {
                if(dp[j][t].first < dp[j-v][t-w].first+1)
                {
                    dp[j][t].first = dp[j-v][t-w].first+1;
                    dp[j][t].second = dp[j-v][t-w].second + w;
                }
                else if(dp[j][t].first == dp[j-v][t-w].first+1)
                {
                    dp[j][t].second = min(dp[j][t].second,dp[j-v][t-w].second + w);
                }

            }
        }
    }
    cout << dp[n][m].first << ' ' << m - dp[n][m].second;
    return 0;
}