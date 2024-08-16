#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10;

int dp[N][3];
int n;

int main()
{
    cin >> n;
    memset(dp,-0x3f,sizeof dp);
    dp[0][2] = 0;
    for(int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        dp[i][0] = max(dp[i-1][0],dp[i-1][2]-w);
        dp[i][1] = dp[i-1][0]+w;
        dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
    }
    cout << max(dp[n][1],dp[n][2]);
    return 0;
}