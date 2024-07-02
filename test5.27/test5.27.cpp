#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int a[N], q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]);

    }
    for (int i = 0; i < n; i++)
    {
        q[a[i]]++;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q[i] > 2) cnt1 += q[i] - 2;
        else if (q[i] == 1) cnt2++;
    }
    if (cnt2 > cnt1) cout << (cnt2 - cnt1) / 2;
    else cout << cnt1 - cnt2;
    return 0;
}

