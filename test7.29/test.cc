
//潜水员
#include <iostream>
#include <cstring>
using namespace std;

const int N = 25, M = 80;
int dp[N][M];

int n,m,k;
int main()
{
    cin >> m >> n >> k;
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    while(k--)
    {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        for(int i = m; i >= 0; i--)
        {
            for(int j = n; j >= 0; j--)
                dp[i][j] = min(dp[i][j],dp[max(0,i-v1)][max(0,j-v2)]+w);
        }
    }
    cout << dp[m][n];
    return 0;
}
