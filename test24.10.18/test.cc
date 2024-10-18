#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 20,P = 1e9+7;

struct F{
    int s0,s1,s2;
}f[N][10][7][7];
LL power7[N],powerP[N];

int mod(LL x,int y)
{
    return ((x%y)+y)%y;
}

void init()
{
    for(int i = 0; i <= 9; i++)
    {
        if(i != 7)
        {
            f[1][i][i%7][i%7] = {1,i,i*i};
        }
    }
    LL power = 10;
    for(int i = 2; i < N; i++,power*=10)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 7) continue;
            for(int x = 0; x < 7;x ++)
            {
                for(int y = 0; y < 7; y++)
                {
                    for(int k = 0; k < 10; k++)
                    {
                        if(k == 7) continue;
                        auto& v1 = f[i][j][x][y],v2 = f[i-1][k][mod(x-j,7)][mod(y-j*power,7)];
                        v1.s0 = mod(v1.s0+v2.s0,P);
                        v1.s1 = mod(v1.s1+
                        power%P*j*v2.s0%P+
                        v2.s1,P);
                        v1.s2 = mod(v1.s2+
                        v2.s2+
                        power%P*(power%P)%P*j*j%P*v2.s0%P+
                        power%P*2*j%P*v2.s1%P
                        ,P);
                    }
                }
            }
        }
    }
    power7[0] = 1;
    for(int i = 1; i < N; i++) power7[i] = power7[i-1]*10%7;
    powerP[0] = 1;
    for(int i = 1; i < N; i++) powerP[i] = powerP[i-1]*10%P;
}

F get(int i,int j,int a,int b)
{
    int s0 = 0,s1 = 0, s2 = 0;
    for(int x = 0; x < 7; x++)
    {
        for(int y = 0; y < 7;y ++)
        {
            if(x != a && y != b)
            {
                auto v = f[i][j][x][y];
                s0 = mod(s0+v.s0,P);
                s1 = mod(s1+v.s1,P);
                s2 = mod(s2+v.s2,P);
            }
        }
    }
    return {s0,s1,s2};
}

int dp(LL n)
{
    if(n==0) return 0;
    vector<int> nums;
    while(n)
    {
        nums.push_back(n%10);
        n /= 10;
    }
    int res = 0;
    LL last_a = 0,last_b = 0;
    for(int i = nums.size()-1; i >= 0; i--)
    {
        int x = nums[i];
        for(int j = 0; j < x; j++)
        {
            if(j == 7) continue;
            int a = mod(-last_a,7);
            int b = mod(-last_b*power7[i+1],7);
            auto v = get(i+1,j,a,b);
            res = mod(res+
            last_b%P*(last_b%P)%P*powerP[i+1]%P*powerP[i+1]%P*v.s0%P+
            last_b%P*powerP[i+1]%P*2*v.s1%P+
            v.s2
            ,P);
        }
        if(x == 7) break;
        last_a += x;
        last_b = last_b*10+x;
        if(!i && last_a%7 && last_b %7) 
            res = mod(res+last_b%P*(last_b%P)%P,P);
    }
    return res;
}
int main()
{
    init();
    int T;
    cin >> T;
    while(T--)
    {
        LL l,r;
        cin >> l >> r;
        cout << mod(dp(r)-dp(l-1),P) << endl;
    }
    return 0;
}