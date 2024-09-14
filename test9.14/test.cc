#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 12,M = 1 << 10;

long long dp[N][N*N][M];
int cnt[M];
vector<int> status;
int n,k;
bool check(int x)
{
    for(int i = 1; i < n; i++)
    {
        if(x >> (i-1) & 1 && x >> i & 1) return false; 
    }
    return true;
}
int count(int x)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(x >> i & 1) cnt++;
    }
    return cnt;
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < 1 << n; i++)
    {
        if(check(i)) 
        {
            status.push_back(i);
            cnt[i] = count(i);
        }
    }
    dp[0][0][0] = 1;
    for(int i = 1; i <= n+1;i++)
    {
        for(int t = 0; t <= k; t++)
        {

            for(auto x : status)
            {
                if(cnt[x] <= t)
                {
                    for(auto y : status)
                    {
                        if(cnt[y] <= t && cnt[x] + cnt[y] <= t)
                        {
                            if(x&y || !check(x|y)) ;
                            else
                            {
                                dp[i][t][x] += dp[i-1][t-cnt[x]][y];
                            }
                        }
                    }
                }

            }

        }
    }
    cout << dp[n+1][k][0] << endl;
    return 0;
}