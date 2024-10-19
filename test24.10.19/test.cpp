#include <iostream>
#include <cstdio>

typedef long long LL;
using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10;

int p[N], d[N];
LL s[M];
int q[M], hh, tt;
bool st[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i], &d[i]);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= n) s[i] = s[i + n] = p[i] - d[i];
        s[i] += s[i - 1];
    }
    for (int i = 1; i < 2 * n; i++)
    {
        while (hh < tt&& q[hh] <= i - n) hh++;
        while (hh < tt && s[q[tt - 1]] >= s[i]) tt--;
        q[tt++] = i;
        if (i >= n && s[q[hh]] >= s[i - n])
        {
            st[i - n + 1] = true;
        }
    }
    d[0] = d[n];
    for (int i = n * 2; i >= 1; i--)
    {
        if (i > n) s[i] = s[i - n] = p[i - n] - d[i - n - 1];
        s[i] += s[i + 1];
    }
    hh = tt = 0;
    for (int i = 2 * n; i > 1; i--)
    {
        while (hh < tt && q[hh] >= i + n) hh++;
        while (hh < tt && s[q[tt - 1]] >= s[i]) tt--;
        q[tt++] = i;
        if (i <= n + 1 && s[q[hh]] >= s[i + n])
            st[i - 1] = true;
    }
    for (int i = 1; i <= n; i++) puts(st[i] ? "TAK" : "NIE");
    return 0;
}