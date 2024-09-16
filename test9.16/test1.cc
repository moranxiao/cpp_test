#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 105,M = 1 << 10;

int dp[2][M][M];
vector<int> status;
vector<int> transfer[M];
int g[N];
int cnt[M];
int n,m;

int count(int x)
{
    int res = 0;
    for(;x; x -= x & -x)
    {
        res ++;
    }
    return res;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 0; j < m; j++)
        {
            char s;
            cin >> s;
            g[i] |= s == 'H' ? 1 << j : 0;  
        }
    }
    for(int i = 0; i < 1 << m; i++)
    {
        if(!(i >> 2 & i || i >> 1 & i)) status.push_back(i);
        cnt[i] = count(i);
    }
    for(auto a : status)
    {
        for(auto b : status)
        {
            if(a & b) continue;
            else transfer[a].push_back(b);
        }
    }
    for(int i = 1; i <= n + 2; i++)
    {
        for(auto a : status)
        {
            for(auto b : transfer[a])
            {
                for(auto c: transfer[b])
                {
                    if(a&c ) continue;
                    else if(g[i] & a) continue;
                    else if(i-1 >= 1 && g[i-1] & b) continue;
                    else
                    {
                        dp[i&1][b][a] = max(dp[i&1][b][a],dp[(i-1)&1][c][b] + cnt[a]);
                    }
                }
            }
        }
    }
    cout << dp[(n+2)&1][0][0] << endl;
    return 0;
}