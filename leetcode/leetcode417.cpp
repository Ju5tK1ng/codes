#include<bits/stdc++.h>
using namespace std;
// 1.2
vector<int> d{-1, 0, 1, 0, -1};
void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j, int m, int n)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + d[k], y = j + d[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] >= matrix[i][j] && !visited[x][y])
        {
            dfs(matrix, visited, x, y, m, n);
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix){
    vector<vector<int>> ans;
    if (matrix.empty() || matrix[0].empty())
    {
        return ans;
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visitedP(m, vector<bool>(n, false));
    vector<vector<bool>> visitedA(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        dfs(matrix, visitedP, i, 0, m, n);
        dfs(matrix, visitedA, i, n - 1, m, n);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(matrix, visitedP, 0, i, m, n);
        dfs(matrix, visitedA, m - 1, i, m, n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visitedP[i][j] && visitedA[i][j])
            {
                ans.push_back(vector<int>{i, j});
            }
        }
    }
    return ans;
}
int main()
{
    int m, n, t;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        matrix.push_back(v);
    }
    vector<vector<int>> ans = pacificAtlantic(matrix);
    for (auto a:ans)
    {
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}