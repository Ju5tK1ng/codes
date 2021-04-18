#include<bits/stdc++.h>
using namespace std;
int mp[1010][1010];
int dx[5] = {-1, 0, 1, 0, -1};
int n, m, t, ans = 0;
void dfs(int i, int j, int d, int cur, int cnt)
{
    if (i < 0 || i >= n || j < 0 || j >= m || cur > t)
    {
        return;
    }
    if (cur != 0 && cur % mp[i][j] == 0)
    {
        cnt++;
    }
    if (i == n - 1 && j == m - 1 && cur == t)
    {
        ans = max(ans, cnt);
    }
    for (int k = 0; k < 4; k++)
    {
        if (k != d)
        {
            dfs(i + dx[k], j + dx[k + 1], (k + 2) % 4, cur + 1, cnt);
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }
    if (n + m - 2 > t || (n + m + t) % 2)
    {
        cout << 0 << endl;
    }
    else
    {
        dfs(0, 0, -1, 0, 0);
    }
    cout << ans << endl;
    return 0;
}