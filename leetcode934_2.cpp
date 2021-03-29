#include<bits/stdc++.h>
using namespace std;
void dfs (vector<vector<int>>& A, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1)
    {
        return;
    }
    A[i][j] = 0x7f3f3f3f;
    dfs(A, i - 1, j, m, n);
    dfs(A, i, j + 1, m, n);
    dfs(A, i + 1, j, m, n);
    dfs(A, i, j - 1, m, n);
}
int shortestBridge(vector<vector<int>>& A) {
    const int maxn = 0x3f3f3f3f;
    int m = A.size(), n = A[0].size();
    bool fliped = false;
    for (int i = 0; i < m; i++)
    {
        if (fliped)
        {
            break;
        }
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                dfs (A, i, j, m, n);
                fliped = true;
                break;
            }
        }
    }
    int ans1 = maxn, ans2 = maxn;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0x7f3f3f3f)
            {
                if (i != 0)
                {
                    ans1 = min(ans1, A[i - 1][j] - 1);
                }
                if (j != 0)
                {
                    ans1 = min(ans1, A[i][j - 1] - 1);
                }
            }
            else if (A[i][j] == 0)
            {
                A[i][j] = maxn;
                if (i != 0)
                {
                    A[i][j] = min(A[i][j], A[i - 1][j] + 1);
                }
                if (j != 0)
                {
                    A[i][j] = min(A[i][j], A[i][j - 1] + 1);
                }
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (A[i][j] == 0x7f3f3f3f)
            {
                if (i != m - 1)
                {
                    ans1 = min(ans1, A[i + 1][j] - 1);
                }
                if (j != n - 1)
                {
                    ans1 = min(ans1, A[i][j + 1] - 1);
                }
            }
            else if (A[i][j] != 1)
            {
                if (i != m - 1)
                {
                    A[i][j] = min(A[i][j], A[i + 1][j] + 1);
                }
                if (j != n - 1)
                {
                    A[i][j] = min(A[i][j], A[i][j + 1] + 1);
                }
            }
        }
    }
    return min(ans1, ans2);
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[i];
        }
        A.push_back(v);
    }
    cout << shortestBridge(A) << endl;
    return 0;
}