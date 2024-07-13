//AcWing 1010. 拦截导弹

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int a[N],b[N],len;
int dp[N];
int n = 1;

int main()
{
    while(cin >> a[n]) n++;
    n--;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[i] <= a[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res,dp[i]);

    for(int i = 1; i <= n; i++)
    {
        int l = 0,r = len-1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(b[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        if(r == len-1 && b[r] < a[i])
        {
            b[len++] = a[i];
        }
        else b[r] = a[i];
    }
    cout << res << endl << len << endl;
    return 0;
}

//AcWing 1016. 最大上升子序列和
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int a[N],dp[N];
int n;

int main()
{
    cin >> n;
    for(int i =1 ; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        for(int j = 1; j < i; j++)
        {
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+a[i]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res,dp[i]);
    cout << res << endl;
    return 0;
}