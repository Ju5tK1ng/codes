#include<bits/stdc++.h>
using namespace std;
void dfs (vector<vector<int>>& A, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 0)
    {
        return;
    }
    A[i][j] = -1;
    dfs(A, i - 1, j, m, n);
    dfs(A, i, j + 1, m, n);
    dfs(A, i + 1, j, m, n);
    dfs(A, i, j - 1, m, n);
}
int shortestBridge(vector<vector<int>>& A) {
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
    int ans1 = 0, ans2 = 0;
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