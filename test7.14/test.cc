//AcWing 1012. 友好城市

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e3+10;

using PII = pair<int,int>;
int dp[N];

int main()
{
    int n;
    cin >> n;
    vector<PII> v;
    for(int i = 1; i <= n; i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(v[i].second > v[j].second) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        res = max(res,dp[i]);
    }
    cout << res << endl;
    return 0;
}