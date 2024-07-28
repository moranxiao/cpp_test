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
//装箱问题
#include <iostream>

using namespace std;

const int N = 2e4+10;

int dp[N];
int n,m;

int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        for(int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j],dp[j-v]+v);
        }
    }
    cout << m - dp[m];
    return 0;
}

//采药
#include <iostream>
using namespace std;

const int N = 1e3+10;

int dp[N];

int n,m;

int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        int v,w;
        cin >> v >> w;
        for(int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j],dp[j-v]+w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}