#include<bits/stdc++.h>
using namespace std;
int num, n, m;
char a[50][50];
void dfs(char c, int si, int sj, int i, int j, bool& ans, int cnt)
{
    if (si == i && sj == j && cnt >= 3)
    {
        ans = true;
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '0' || a[i][j] != c || ans == true)
    {
        return;
    }
    a[i][j] = '0';
    dfs(c, si, sj, i, j + 1, ans, cnt + 1);
    dfs(c, si, sj, i + 1, j, ans, cnt + 1);
    dfs(c, si, sj, i, j - 1, ans, cnt + 1);
    dfs(c, si, sj, i - 1, j, ans, cnt + 1);
    a[i][j] = c;
}
int main()
{
    cin >> num;
    while (num--)
    {
        cin >> n >> m;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != '0')
                {
                    dfs(a[i][j], i, j, i, j, ans, 0);
                    if (ans)
                    {
                        break;
                    }
                }
            }
            if (ans == true)
            {
                break;
            }
        }
        ans == true ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}