#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110,M = 25e3+10;

bool dp[M];
int a[N];

int T,n;
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memset(dp,0,sizeof dp);
        sort(a,a+n);
        dp[0] = true;
        int res = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = a[i-1]; j <= a[n-1]; j++)
            {
                dp[j] |= dp[j-a[i-1]];
            }
            if(!dp[a[i]]) res++;
        }
        cout << res << endl;
    }
    return 0;
}