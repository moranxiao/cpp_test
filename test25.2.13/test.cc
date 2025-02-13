#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e3+10;

double dist[N],g[N][N];
bool st[N];
int n,m;
int start,e;

void dijkstra()
{
    dist[start] = 1;
    for(int i = 0; i < n-1; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if( !st[j] && ( t == -1 || dist[j] > dist[t])) t = j;
        }
        st[t] = true;
        for(int j = 1; j <= n; j++)
        {
            if(st[j]) continue;
            dist[j] = max(dist[j],dist[t] * g[t][j]);
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d", &a,&b,&c);
        g[a][b] = g[b][a] = (100.0 - c) /100;
    }
    cin >> start >> e;
    dijkstra();
    printf("%.8lf", 100 / dist[e]);
    return 0;
}