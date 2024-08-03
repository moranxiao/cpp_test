#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3+10;

int dp[N],g[N];

int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int v,w,s;
        cin >> v >> w >> s;
        memcpy(g,dp,sizeof dp);
        if(s == -1) s = 1;
        if(s == 0)
        {
            for(int j = v; j <= m; j++) dp[j] = max(dp[j],dp[j-v]+w);
        }
        else
        {
            int t = 1;
            while(t <= s)
            {
                int v1 = v*t, w1 = w*t;
                for(int j = m; j >= v1; j--)
                {
                    dp[j] = max(dp[j],dp[j-v1]+w1);
                }
                s -= t;
                t *= 2;
            }
            if(s)
            {
                int v1 = v*s, w1 = w*s;
                for(int j = m; j >= v1; j--)
                {
                    dp[j] = max(dp[j],dp[j-v1]+w1);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}