#include <bits/stdc++.h>
using namespace std;
bool a[210][210];
int T, m, n, ans, t, cnt;
void dfs(int i, int j)
{
    if (!(i >= 0 && i < m && j >= 0 && j < n) || !a[i][j])
    {
        ans = max(ans, cnt);
        return;
    }
    a[i][j] = false;
    cnt++;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main()
{
    cin >> T >> n >> m;
    while (T--)
    {
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> t;
                a[i][j] = t ? true : false;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j])
                {
                    cnt = 0;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
