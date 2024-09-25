#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 12, M = 1 << 12,INF = 0x3f3f3f3f;

int dist[N][N],g[N][M];
int dp[M][N];

int main()
{
    int n,m;
    cin >> n >> m;
    memset(dist,0x3f,sizeof dist);
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    while(m--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        a--,b--;
        dist[a][b] = dist[b][a] = min(dist[a][b],w);
    }
    memset(g,0x3f,sizeof g);
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < 1 << n; j++)
        {
            if(j&1<<i) continue;
            for(int k = 0; k < n; k++)
            {
                if(j&1<<k)
                {
                    g[i][j] = min(g[i][j],dist[i][k]);
                }
            }
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(int i = 0; i < n; i++) dp[1 << i][0] = 0;
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = i-1&i; j; j = j-1&i)
        {
            int x = i-j;
            int cost = 0;
            for(int k = 0; k < n; k++)
            {
                if(j&1<<k)
                {
                    cost += g[k][x];
                }
                if(cost >= INF) break;
            }
            if(cost >= INF) continue;
            for(int k = 1; k < n; k++)
            {
                dp[i][k] = min(dp[i][k],dp[x][k-1]+cost*k);
            }
            
        }
    }
    int res = INF;
    for(int i = 0; i < n; i++)
    {
        res = min(res,dp[(1<<n)-1][i]);
    }
    cout << res <<endl;
    return 0;
}