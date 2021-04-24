#include<bits/stdc++.h>
using namespace std;
int a[110][110], b[110][110], c[110][110], d[110][110], e[110][110];
int main()
{
    int n, D, ans = 0;
    cin >> n >> D;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = b[i][j - 1] + a[i][j];
            if (j >= D)
            {
                ans = max(ans, b[i][j] - b[i][j - D]);
            }
            c[i][j] = c[i - 1][j] + a[i][j];
            if (i >= D)
            {
                ans = max(ans, c[i][j] - c[i - D][j]);
            }
            d[i][j] = d[i - 1][j - 1] + a[i][j];
            if (i >= D && j >= D)
            {
                ans = max(ans, d[i][j] - d[i - D][j - D]);
            }
            e[i][j] = e[i - 1][j + 1] + a[i][j];
            if (i >= D && j <= n - D + 1)
            {
                ans = max(ans, e[i][j] - e[i - D][j + D]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}