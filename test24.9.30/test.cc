#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;

int q[N];
int dp[N][N];

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q[i+n] = q[i] = x;
    }
    for(int len = 3; len <= n+1; len++)
    {
        for(int i = 1; i+len-1 <= n*2; i++)
        {
            int j = i + len-1;
            for(int k = i+1; k < j; k++)
            {
                
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+q[i]*q[k]*q[j]);
            }
        }
    }
    int m = 0;
    for(int i = 1; i <= n; i++)
    {
        m = max(m,dp[i][i+n]);
    }
    cout << m << endl;
    return 0;
}