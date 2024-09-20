#include <iostream>
#include <cmath>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<double,double> PDD;

const int N = 18, M = 1 << 18;
const double eps = 1e-8;

PDD point[N];
int path[N][N];
int dp[M];

int cmp(double x,double y)
{
    if(fabs(x-y) < eps)
        return 0;
    return x > y ? 1 : -1;
}
int main()
{
    int T,n,m;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> point[i].x >> point[i].y;
        }
        memset(path,0,sizeof path);
        for(int i = 0; i < n; i++)
        {
            path[i][i] = 1 << i;
            //虚位以待
            for(int j = 0; j < n; j++)
            {
                double x1 = point[i].x, y1 = point[i].y;
                double x2 = point[j].x, y2 = point[j].y;
                if(!cmp(x1,x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                double b = y1 / x1 - a * x1;
                if(cmp(a,0) != -1) continue; 
                for(int k = 0; k < n; k++)
                {
                    double x = point[k].x, y = point[k].y;
                    if(!cmp(a*x*x+b*x,y))
                    {
                        path[i][j] |= 1 << k;
                    }
                }
            }
        }
        memset(dp,0x3f,sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < 1 << n; i++)
        {
            int x = 0;
            for(int j = 0; j < n; j++)
            {
                if(!(i & 1 << j))
                {
                    x = j;
                    break;
                }
            }
            for(int k = 0; k < n; k++)
            {
                int new_status = i | path[x][k];
                dp[new_status] = min(dp[new_status],dp[i]+ 1);
            }
        }
        cout << dp[(1 << n) -1]  << endl; 
    }
    return 0;
}