#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int dp[N][N];
int h[N],e[N],ne[N],idx;
int v[N],w[N];
int n,m;
void add(int a,int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int x = e[i];
        dfs(x);
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k <= j; k++)
            {
                dp[u][j] = max(dp[u][j], dp[x][k] + dp[u][j-k]);
            }
        }
    }
    for(int i = m; i; i--)
    {
        if(i >= v[u])
            dp[u][i] = dp[u][i-v[u]]+w[u];
        else dp[u][i] = 0;
    }
}
int main()
{
    cin >> n >> m;
    int root;
    memset(h,-1,sizeof h);
    for(int i = 1; i <= n; i++)
    {
        int a,b,p;
        cin >> a >> b >> p;
        if(p == -1) root = i;
        else add(p,i);
        v[i] = a;
        w[i] = b;
    }
    dfs(root);
    cout << dp[root][m] << endl;
    return 0;
}