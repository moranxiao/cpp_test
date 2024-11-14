#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1e3+10,M = 2e4+10;
int h[N],rh[N],e[M],ne[M],w[M],idx;
int S,T,K,n,m;
int dist[N];
bool st[N];
int cnt[N];

void add(int h[],int a,int b,int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    heap.push({0,T});
    dist[T] = 0;
    while(!heap.empty())
    {
        int t = heap.top().second;
        heap.pop();
        if(st[t]) continue;
        st[t] = true;
        for(int i = rh[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t]+w[i])
            {
                dist[j] = dist[t]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}

int astar()
{
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> heap;
    heap.push({dist[S],{0,S}});
    while(!heap.empty())
    {
        int t = heap.top().second.second;
        int d = heap.top().second.first;
        heap.pop();
        cnt[t] ++;
        if(cnt[T] == K)
        {
            return d;
        }
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(cnt[j] < K)
                heap.push({dist[j]+ d + w[i],{d+w[i],j}});
        }
    }
    return -1;
}

int main()
{
    memset(h,-1,sizeof h);
    memset(rh,-1,sizeof rh);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(h,a,b,c);
        add(rh,b,a,c);
    }
    cin >> S >> T >> K;
    //当起点和终点相同时，默认有一个长度为0的最短路，要将其排除出去
    if(S == T) K++;
    dijkstra();
    if(dist[S] == 0x3f3f3f3f) cout << -1 << endl; 
    else
    {
        cout << astar() << endl;
    }
    return 0;
}