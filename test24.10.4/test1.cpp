#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4+10,M = 2*N;

int h[N],e[M],ne[M],idx;
int q[N];
bool st[N];
int res;
int n;

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u,int parent)
{
    int d1 = 0,d2 = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int t = e[i];
        if(t == parent) continue;
        int d = dfs(t,u) + 1;
        if(d > d1)
        {
            d2 = d1;
            d1 = d;
        }
        else if(d > d2) d2 = d;
    }
    res = max(res,d1+d2);
    st[u] = true;
    return d1;
}
int main()
{
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 1; i < n; i++)
    {
        for(int j = 2; j <= n/i; j++)
        {
            q[i*j] += i;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(q[i] < i)
        {
            add(i,q[i]);
            add(q[i],i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!st[i] && q[i] < i)
            dfs(i,-1);
    }
    cout << res << endl;
    return 0;
}