#include <iostream>
#include <cstdio>


using namespace std;
const int maxn = 1005;
int arr[maxn][maxn] = { 0 };
int n;

bool isCorrect()
{
    int i, j;
    int days;
    if (n % 2 == 0) 
        days = n - 1;
    else
        days = n;
    bool* isAppearence = new bool[n + 1];
    for (i = 1; i <= n; i++) //行
    {
        fill(isAppearence, isAppearence + n + 1, false); //初始化数组
        for (j = 1; j <= days; j++)
        {
            int t = arr[i][j];
            if (t == 0)
                continue;
            if (isAppearence[t])  //在这一行中之前已经出现过了
                return false;
            isAppearence[t] = true;
            if (arr[t][j] != i || t > n || t < 1) //选手t在第j天的对手必须是i,t必须是正确选手1~n
                return false;
        }
    }
    delete[] isAppearence;
    return true;
}
void Union(int left, int mid, int right)
{
    int i, j;
    int size = right - left + 1;
    if (mid % 2 == 1) //如果size为奇数，需要首先填补前几天的空白
    {
        for (i = left; i <= mid; i++)
            for (j = 1; j <= size; j++)
            {
                if (arr[i][j] > mid) //这个位置是空的
                {
                    arr[i][j] = i + mid;
                    arr[i + mid][j] = i;
                    break;
                }
            }
    }
    //下面开始合并
    if (mid % 2 == 0)
    {
        for (j = mid; j < right; j++)
            for (i = 1; i <= mid; i++)
            {
                int t = arr[i + mid][j - mid];
                arr[i][j] = t;
                arr[t][j] = i;
            }
    }
    else {
        //结合规律，开始合并
        //size=6 mid=3 left=1 right=6
        for (j = mid + 1; j < right; j++)
            for (i = 1; i <= mid; i++)
            {
                int t = i + j;
                if (t > right)
                    t -= mid;
                arr[i][j] = t;
                arr[t][j] = i;
            }
    }

}
void copyTable(int left, int mid, int right) //复制函数
{
    int size = right - left + 1;
    int i, j, m;
    if (size % 2 == 1) //奇数
        m = size;
    else
        m = size - 1;
    for (i = right; i > mid; i--)
        for (j = 1; j <= m; j++)
            arr[i][j] = arr[i - mid][j] + mid;
}
void raceTable(int left, int right)
{
    int size = right - left + 1;
    if (size == 2)
    {
        arr[left][1] = right;
        arr[right][1] = left;
        return;
    }
    if (size % 2 == 1)
    {
        raceTable(left, right + 1);
        return;
    }
    //以下是size是2的倍数
    int mid = (left + right) / 2;
    raceTable(left, mid);
    copyTable(left, mid, right); //直接复制上面计算得到的
    Union(left, mid, right);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        arr[i][0] = i;
    raceTable(1, n);
    int t = n % 2 == 0 ? n - 1 : n;
    for (int i = 1; i <= n; i++)
    {
        printf("%d: ", i);
        for (int j = 1; j <= t; j++)
        {
            if (arr[i][j] == n + 1) //空闲时间
                arr[i][j] = 0;
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    if (isCorrect())
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

