#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> a;
int m, n, ans = 0, cnt;

void dfs(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || !a[i][j])
    {
        return;
    }
    cnt++;
    a[i][j] = false;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main()
{
    char c;
    while ((c = getchar()) != ']')
    {
        vector<bool> t;
        while ((c = getchar()) != ']')
        {
            if (c == '0')
            {
                t.push_back(false);
            }
            else if (c == '1')
            {
                t.push_back(true);
            }
        }
        a.push_back(t);
    }
    m = a.size();
    n = a[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
