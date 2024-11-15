#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int,int> PII;

const int N = 110;

char g[N][N];
int n,T;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
bool st[N][N];
bool dfs(PII start,PII end)
{
    if(start == end) return true;
    st[start.first][start.second] = true;
    for(int i = 0; i < 4; i++)
    {
        int x = start.first + dx[i],y = start.second + dy[i];
        if(x < 0 || x >= n || y < 0 || y >= n) continue;
        if(st[x][y] || g[x][y] == '#') continue;
        if(dfs({x,y},end)) return true;
    }
    return false;
}

int main()
{
    cin >> T;
    while(T--)
    {
        memset(st,0,sizeof st);
        cin >> n;
        for(int i = 0; i < n; i++)
            scanf("%s", g[i]);
        int a1,b1,a2,b2;
        cin >> a1 >> b1>> a2 >> b2;
        PII start = {a1,b1};
        PII end = {a2,b2};
        if(g[a1][b1] == '#') cout << "NO" << endl;
        else{
            if(dfs(start,end)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        
    }
    return 0;
}