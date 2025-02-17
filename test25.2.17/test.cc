#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 25e2+10 ,M = 15e3;

int dist[N];
bool st[N];
int h[N],e[M],ne[M],w[M],idx;
int n,m,s,te;

void add(int a,int b,int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    st[s] = true;
    while(q.size())
    {
        int t = q.front();
        q.pop();

        for(int i = h[t]; ~i; i = ne[i])
        {
            int k = e[i];
            if(dist[t] + w[i] < dist[k])
            {
                dist[k] = dist[t] + w[i];
                if(!st[k]) q.push(k);
            }
        }
        st[t] = false;
    }
}

int main()
{
    cin >> n >> m >> s >> te;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    spfa();
    cout << dist[te] << endl;
    return 0;
}