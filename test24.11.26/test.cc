//1.搜索性优化--找分支数量最少的点
//2.可行性剪枝
//3.位运算优化--col&cell&row可以直接确定有哪些数字可以被选
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 9,M = 1 << N;
int col[N],row[N],cell[3][3];
int ones[M],map[M];
char str[100];

//初始化状态数组，0表示不可填，1表示可填
void init()
{
    for(int i = 0; i < N; i++) col[i] = row[i] = (1 << N)-1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cell[i][j] = (1<<N)-1;
}

int lowbit(int x)
{
    return x & -x;
}

void draw(int x,int y,int t,bool is_set)
{
    if(is_set) str[x*N+y] = t + '1';
    else str[x*N+y] = '.';
    
    int v = 1 << t;
    if(!is_set) v = -v;
    
    col[y] -= v;
    row[x] -= v;
    cell[x/3][y/3] -= v;
}

int get(int x,int y)
{
    return col[y] & row[x] & cell[x/3][y/3];
}

bool dfs(int cnt)
{
    if(!cnt) return true;
    int minv = 10;
    int x, y;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(str[i*N+j] == '.')
            {
                int t = get(i,j);
                //这里不要判断t是否为0，因为如果为0，则说明此状态错误，应该直接返回false
                if(minv > ones[t])
                {
                    minv = ones[t];
                    x = i;
                    y = j;
                }
            }

        }
    }
    
    int t = get(x,y);
    int k;
    for(t;k = lowbit(t); t -= k)
    {
        draw(x,y,map[k],true);
        if(dfs(cnt-1)) return true;
        draw(x,y,map[k],false);
    }
    return false;
}

int main()
{
    //提前处理ones[i]--(i中1的个数)
    for(int i = 0; i < M; i++)
    {
        for(int x = i; lowbit(x); x -= lowbit(x))
            ones[i]++;
    }
    //提前处理map[i]--(以2为底i的对数)
    for(int i = 0; i < N; i++)
    {
        map[1 << i] = i;
    }
    
    while(cin >> str, str[0] != 'e')
    {
        int cnt = 0;
        init();
        for(int i = 0,k = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++,k++)
            {
                if(str[k] != '.')
                {
                    draw(i,j,str[k]-'1',true);
                }
                else cnt++;
            }
        }
        dfs(cnt);
        puts(str);
    }
    return 0;
}