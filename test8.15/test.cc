#include <iostream>
#include <cstring>

using namespace std;

const int N = 55, mod = 1e9+7;

int dp[N][N];
char s[N];
int ne[N];
int p[N][26];
int n,m;

int main()
{
    cin >> n >> (s+1);
    m = strlen(s+1);
    for(int i = 2,j = 0;i <= m; i++)
    {
        while(j && s[j+1] != s[i]) j = ne[j];
        if(s[i] == s[j+1]) j++;
        ne[i] = j;
    }
    for(int j = 0; j < m; j++)
    {
        for(char k = 'a'; k <= 'z'; k++)
        {
            int u = j;
            while(u && s[u+1] != k) u = ne[u];
            if(s[u+1] == k) u++;
            p[j][k-'a'] = u;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(char k = 'a'; k <= 'z'; k++)
            {
                int u = p[j][k-'a'];
                dp[i][u] = (dp[i][u] + dp[i-1][j]) % mod; 
            }
        }
    }
    int res = 0;
    for(int i = 0; i < m; i++) res = (res + dp[n][i]) % mod;
    cout << res << endl;
    return 0;
}