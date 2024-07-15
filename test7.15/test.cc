//AcWing 482. 合唱队形

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int a[N],dp1[N],dp2[N];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        dp1[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(a[i] > a[j]) dp1[i] = max(dp1[i],dp1[j]+1);
        }
    }
    for(int i = n; i >= 1; i--)
    {
        dp2[i] = 1;
        for(int j = n; j > i; j--)
        {
            if(a[i] > a[j]) dp2[i] = max(dp2[i],dp2[j]+1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res,dp1[i]+dp2[i]-1);
    cout << n - res << endl;
    return 0;
}