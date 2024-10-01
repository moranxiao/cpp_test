//先不写高精度，把样例做对，再把需要高精度的部分替换成高精度
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;
const int N = 55,M = 35,INF = 1e9;

int q[N];
int dp[N][N][M];
int n;

void add(int a[],int b[])
{
    int t = 0;
    for(int i = 0; i < M; i++)
    {
        t = a[i] + b[i] + t;
        a[i] = t%10;
        t /= 10;
    }
}
void mul(int a[],LL b)
{
    LL tmp = 0;
    for(int i = 0; i < M; i++)
    {
        tmp = a[i]*b+tmp;
        a[i] = tmp%10;
        tmp /= 10;
    }
}
int cmp(int a[],int b[])
{
    for(int i = M-1; i >= 0; i--)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i+len-1 <= n; i++)
        {
            int j = i+len-1;
            dp[i][j][M-1] = 1;
            for(int k = i+1; k < j; k++)
            {
                int tmp[M];
                memset(tmp,0,sizeof tmp);
                tmp[0] = q[i];
                mul(tmp,q[j]);
                mul(tmp,q[k]);
                add(tmp,dp[i][k]);
                add(tmp,dp[k][j]);
                if(cmp(tmp,dp[i][j]) == -1)
                {
                    memcpy(dp[i][j],tmp,sizeof tmp);
                }
            }
        }
    }
    int len = M-1;
    while(!dp[1][n][len]) len--;
    for(int i = len; i >= 0; i--)
        cout << dp[1][n][i];
    return 0;
}