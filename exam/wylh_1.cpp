#include<bits/stdc++.h>
using namespace std;
int n, m, t, r1, r2, c1, c2, s, A;
bool cmp0(vector<int> x, vector<int> y)
{
    return x[s] < y[s];
}
bool cmp1(vector<int> x, vector<int> y)
{
    return x[s] > y[s];
}
int main()
{
    cin >> n >> m >> t;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> ans = v;
    for (int k = 0; k < t; k++)
    {
        cin >> r1 >> r2 >> c1 >> c2 >> s >> A;
        if (A == 0)
        {
            stable_sort(ans.begin() + r1, ans.begin() + r2 + 1, cmp0);
        }
        else
        {
            stable_sort(ans.begin() + r1, ans.begin() + r2 + 1, cmp1);
        }
        for (int i = r1; i <= r2; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j < c1 || j > c2)
                {
                    ans[i][j] = v[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j];
            if (j != m) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
