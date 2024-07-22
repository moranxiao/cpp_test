#include <iostream>

using namespace std;

const int N = 12000;

int w[N],v[N];
int dp[N];
int n,m;

int main()
{
    cin >> n >> m;
    int cnt = 0;
    while(n--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int k = 1;
        while(c >= k)
        {
            cnt++;
            w[cnt] = k*b;
            v[cnt] = k*a;
            c -= k;
            k *= 2;
        }
        if(c)
        {
            cnt++;
            w[cnt] = c*b;
            v[cnt] = c*a;
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}