#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 50,M = 1 << 25;

int q[N];
int weight[M],cnt;
int n,m;
int res;

void dfs1(int u,int now,int n1)
{
    if(u == n1)
    {
        weight[cnt++] = now;
        return;
    }
    if((long long)now + q[u] <= m) dfs1(u+1,now+q[u],n1);
    dfs1(u+1,now,n1);
}

void dfs2(int u,int now)
{
    if(u == n) 
    {
        int l = 0,r = cnt-1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(now + (long long)weight[mid] <= m) l = mid;
            else r = mid - 1;
        }
        if(now + (long long)weight[l] <= m) res = max(res,now+weight[l]);
        return;
    }
    if(now+(long long)q[u] <= m) dfs2(u+1,now+q[u]);
    dfs2(u+1,now);
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> q[i];
    sort(q,q+n,greater<int>());
    int n1 = n/2;
    dfs1(0,0,n1);
    sort(weight,weight+cnt);
    auto it = unique(weight,weight+cnt);
    cnt = it-weight;
    dfs2(n1,0);
    cout << res << endl;
    return 0;
}