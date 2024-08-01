#include <iostream>

using namespace std;

const int N = 3e3+10;

long long dp[N];

int n,m;

int main()
{
    cin >> n >> m;
    dp[0]++;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;

        for(int j = v; j <= m; j++)
        {
            dp[j] += dp[j-v];
        }
    }
    cout << dp[m];
    return 0;
}
