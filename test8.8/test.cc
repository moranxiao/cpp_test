#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110,M = 1e5+10;

struct Stone{
    int s,e,l;
    bool operator<(const Stone& other)
    {
        return s*other.l < other.s * l;
    }
} stone[N];

int dp[M];
int T,n;

int main()
{
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        cin >> n;
        int maxtime = 0;
        for(int i = 0; i < n; i++)
        {
            int s,e,l;
            cin >> s >> e >> l;
            stone[i] = {s,e,l};
            maxtime += s;
        }
        sort(stone,stone+n);
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int s = stone[i].s,e = stone[i].e,l = stone[i].l;
            for(int j = maxtime; j >= s; j--)
            {
                if(dp[j-s] != -1)
                    dp[j] = max(dp[j],dp[j-s] + e - l*(j-s));
            }
        }
        int res = 0;
        for(int i = 0; i <= maxtime; i++) res = max(res,dp[i]);
        cout << "Case #" << k << ": " << res << endl;
    }
    return 0;
}