#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e4+10;

int dp[N],g[N],q[N];

int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n;  i++)
    {
        int v,w,s;
        cin >> v >> w >> s;
        memcpy(g,dp,sizeof dp);
        for(int j = 0; j < v; j++)
        {
            int hh = 0,tt = -1;
            for(int k = j; k <= m; k += v)
            {
                if(hh <= tt && q[hh] < k - s*v) hh++;
                while(hh <= tt && g[q[tt]] - q[tt]/v*w <= g[k] - k/v*w) tt--;
                q[++tt] = k;
                dp[k] = g[q[hh]] + (k-q[hh])/v*w;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}