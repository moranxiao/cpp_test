#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 25,INF = 1e9;

int R[N],H[N];
int minv[N],mins[N];
int n,m;
int res = INF;

void dfs(int u,int v,int s)
{
    if(v + minv[u] > n) return;
    if(s + mins[u] >= res) return;
    if(s + 2*(n-v)/R[u+1] >= res) return;
    
    if(!u)
    {
        if(v == n) res = s;
        return;
    }
    
    for(int r = min(R[u+1]-1,(int)sqrt(n-v)); r >= u; r--)
    {
        for(int h = min(H[u+1]-1,(n-v)/r/r); h >= u; h--)
        {
            R[u] = r;
            H[u] = h;
            int t = 0;
            if(u == m) t = r*r;
            dfs(u-1,v+r*r*h,s+r*2*h+t);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        minv[i] = minv[i-1] + i*i*i;
        mins[i] = mins[i-1] + 2*i*i;
    }
    R[m+1] = H[m+1] = INF;
    dfs(m,0,0);
    if(res == INF) res = 0;
    cout << res << endl;
    return 0;
}