#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int N = 510;

int g[N][N];
int dist[N];
bool st[N];
int n,m;

void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n-1; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        st[t] = true;
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
}


int main()
{
    cin >> m >> n;
    getchar();
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        int arr[N],idx = 0;
        
        while(ss >> arr[idx])
        {
            idx++;
            for(int i = 0; i < idx-1; i++)
            {
                g[arr[i]][arr[idx-1]] = 1;
            }
        }

    }
    dijkstra();
    if(dist[n] == 0x3f3f3f3f) cout << "NO" << endl;
    else cout << dist[n]-1 << endl;
    return 0;
}