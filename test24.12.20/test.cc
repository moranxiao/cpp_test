#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5+10,M = 1e5+10;

int st[N],dist[N];
int h[N],e[M],w[M],ne[M],idx;
int n,m;

void add(int a,int b,int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void spfa()
{
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(q.size())
    {
        int t = q.front(); q.pop();
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[t] + w[i] < dist[j])
            {
                if(!st[j]) 
                {
                    q.push(j);
                }
                dist[j] = dist[t] + w[i];
                st[j] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d", &a,&b,&c);
        add(a,b,c);
    }
    spfa();
    if(dist[n] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else cout << dist[n] << endl;
    return 0;
}