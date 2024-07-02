#include <iostream>
#include <cstring>
using namespace std;

int g[10][10];
bool col[10][10], row[10][10], st[10][10];

bool is_legal()
{
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(st, 0, sizeof st);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (g[i][j] <= 0 || g[i][j] > 9) return false;
            int t = g[i][j];
            if (col[j][t] || row[i][t] || st[(i - 1) / 3 * 3 + (j - 1) / 3][t]) return false;
            col[j][t] = row[i][t] = st[(i - 1) / 3 * 3 + (j - 1) / 3][t] = true;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cin >> g[i][j];
            }
        }
        if (is_legal()) cout << '1';
        else cout << '0';
        cout << endl;
    }
    return 0;
}