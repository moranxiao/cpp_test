#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3+10,mod = 1e9+7;
int dp[N],count[N]; //count[i]表示体积不超过i的方案中取得最大价值的方案数,滚动数组表示
int n,m;

int main()
{
    cin >> n >> m;
    //第一层一个物品也不选，那么体积不超过i的方案中取得最大价值的方案数为1，即一个物品也不选
    for(int i = 0; i <= m; i++) 
    {
        count[i] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        int v,w;
        cin >> v >> w;
        for(int j = m; j >= v; j--)
        {
            if(dp[j] < dp[j-v]+w) //选择第i件物品的价值比不选大，那么方案数更改
                count[j] = count[j-v];
            else if(dp[j] == dp[j-v]+w) //选与不选的价值相等，那么方案数相加
                count[j] = (count[j-v]+count[j])%mod;
            dp[j] = max(dp[j],dp[j-v]+w);
        }
    }
    cout << count[m] << endl;
    return 0;
}