#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef pair<int,int> PII;

const int N = 25;

char g[N][N];
bool st[N][N];
int r,c;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int dfs(PII start)
{
    int a = start.first,b = start.second;
    if(g[a][b] == '#' || st[a][b]) return 0;
    int res = 1;
    st[a][b] = true;
    for(int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if(x < 0 || x >= r || y < 0 || y >= c) continue;
        res += dfs({x,y});
    }
    return res;
}

int main()
{
    while(cin >> c >> r, r || c)
    {
        memset(st,0,sizeof st);
        
        PII start;
        for(int i = 0; i < r; i++)
        {
            scanf("%s", g[i]);
            for(int j = 0; j < c; j++)
            {
                if(g[i][j] == '@') start = {i,j}; 
            }
        }
        cout << dfs(start) << endl;
    }
    return 0;
}