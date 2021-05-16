#include<bits/stdc++.h>
using namespace std;
vector<int> d{-1, 0, 1, 0, -1};
int dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
{
    grid[i][j] = 0;
    int area = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + d[k], y = j + d[k + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
        {
            area += dfs(grid, x, y, m, n);
        }
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }
    int maxArea = 0, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                maxArea = max(maxArea, dfs(grid, i, j, m, n));
            }
        }
    }
    return maxArea;
}
int main()
{
    int m, n, t;
    cin >> m >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            v.push_back(t);
        }
        grid.push_back(v);
    }
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}