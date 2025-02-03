#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int g[N][N];
int weight[N],grade[N];
int dist[N];
bool st[N];
int n,m;

void dijkstra(int gd)
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[n+1] = 0;
    for(int i = 0; i <= n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n+1; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        for(int j = 1; j <= n+1; j++)
        {
            if(!st[j] && gd <= grade[j] && gd+m >= grade[j])
            {
                dist[j] = min(dist[j],dist[t] + g[t][j]);
            }
        }
        st[t] = true;
    }
}

int main()
{
    cin >> m >> n;
    memset(g,0x3f,sizeof g);
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> weight[i] >> grade[i] >> k;
        while(k--)
        {
            int t;
            cin >> t;
            cin >> g[t][i];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        g[n+1][i] = weight[i];
    }
    
    int ans = 0x3f3f3f3f;
    for(int i = 1; i + m <= N; i++)
    {
        dijkstra(i);
        ans = min(ans,dist[1]);
    }
    cout << ans << endl;
    return 0;
}