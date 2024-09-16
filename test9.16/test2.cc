#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 14,M = 1 << 12, mod = 1e8;

int dp[N][M];
int g[N];
vector<int> status;
vector<int> transfer[M];
int n,m;
bool check(int x)
{
    for(int i = 1; i < m; i++)
    {
        if(x & 1 << (i-1) && x & 1 << i)
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int s = 0;
            cin >> s;
            g[i] |= !(s&1) << j;
        }
    }
    for(int i = 0; i < 1 << m;i++)
    {
        // if(check(i)) status.push_back(i);
        if(!(i & i >> 1)) status.push_back(i); // 更简洁方便
    }
    for(auto a : status)
    {
        for(auto b : status)
        {
            if(a & b) continue;
            else
                transfer[a].push_back(b);
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        for(auto a : status)
        {
            if(a&g[i]) continue;
            for(auto b : transfer[a])
            {
                dp[i][a] = (dp[i][a] + dp[i-1][b]) % mod;
            }
        }
    }
    cout << dp[n+1][0];
    return 0;
}