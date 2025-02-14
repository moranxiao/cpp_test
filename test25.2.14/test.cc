#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N = 810,M = 3e3;

int h[N],e[M],ne[M],w[M],idx;
int dist[N];
int cnt[N];
bool st[N];
int T,n,m;

void add(int a,int b,int c)
{
    e[idx] = b,w[idx] = c,ne[idx] = h[a], h[a] = idx++;
}

int spfa(int s)
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    st[s] = true;
    while(q.size())
    {
        int t = q.front(); q.pop();
        for(int i = h[t]; ~i; i = ne[i])
        {
            int k = e[i];
            if(dist[k] > dist[t] + w[i])
            {
                dist[k] = dist[t] + w[i];
                if(!st[k])
                {
                    st[k] = true;
                    q.push(k);
                }
            }
        }
        st[t] = false;
    }
    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == 0x3f3f3f3f)
        {
            if(cnt[i] == 0) continue;
            else return dist[i];
        }
        ret += cnt[i]*dist[i];
    }
    return ret;
}
int main()
{
    cin >> T >> n >> m;
    for(int i = 0; i < T; i++)
    {
        int u;
        cin >> u;
        cnt[u]++;
    }
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    int res = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        res = min(res,spfa(i));
    }
    cout << res << endl;
    return 0;
}