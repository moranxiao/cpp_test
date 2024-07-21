#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3e3+10;
 
int a[N],b[N];
int dp[N][N];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         dp[i][j] = dp[i-1][j];
    //         if(a[i] == b[j])
    //         {
    //             dp[i][j] = max(1,dp[i][j]);
    //             for(int k = 1; k < j; k++)
    //             {
    //                 if(b[k] < b[j])
    //                     dp[i][j] = max(dp[i][j],dp[i-1][k]+1);
    //             }
    //         }

    //     }
    // }
    for(int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for(int j = 1; j <= n; j++)
        {
            if(b[j] < a[i])
                maxv = max(maxv,dp[i-1][j]+1);
            dp[i][j] = dp[i-1][j];
            if(a[i] == b[j])
            {
                dp[i][j] = max(dp[i][j],maxv);
            }

        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        res = max(res,dp[n][i]);
    }
    cout << res << endl;
    return 0;
}