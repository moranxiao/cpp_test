#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e4+10,M = N*2;

int h[N],e[M],ne[M],w[M],idx;
int n,res;

void add(int a,int b,int c)
{
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}
int dfs(int u,int parent)
{
    int m1 = 0, m2 = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int x = e[i];
        if(x == parent) continue;
        int d = dfs(x,u) + w[i];
        if(d > m1)
        {
            m2 = m1;
            m1 = d;
        }
        else if(d > m2)
        {
            m2 = d;
        }
    }
    res = max(res,m1+m2);
    return m1;
}
int main()
{
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 0; i < n-1; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);
    cout << res << endl;
    return 0;
}