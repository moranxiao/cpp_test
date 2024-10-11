#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 32;

int K,B;

int f[N][N];

void init()
{
    f[0][0] = 1;
    for(int i = 1; i < N; i++)
    {
        f[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = f[i-1][j-1] + f[i-1][j];
        }
    }
}

int dp(int n)
{
    if(n == 0) return 0;
    int res = 0;
    vector<int> nums;
    while(n)
    {
        nums.push_back(n%B);
        n /= B;
    }
    int last = 0; // 高于本位所在位的 所含1的个数
    for(int i = nums.size()-1; i >= 0; i--)
    {
        int x = nums[i];
        if(x)
        {
            res += f[i][K-last];
            if(x > 1)
            {
                if(last < K)
                    res += f[i][K-last-1];
                break;
            }
            else
            {
                last++;
                if(last > K) break;
            }
        }
        if(!x && last == K) res++;
    }
    return res;
}

int main()
{
    init();
    int l,r;
    cin >> l >> r >> K >> B;
    cout << dp(r) - dp(l-1) << endl;
    return 0;
}