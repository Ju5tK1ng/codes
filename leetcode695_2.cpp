#include<bits/stdc++.h>
using namespace std;
// 2.0
vector<int> d{-1, 0, 1, 0, -1};
int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty())
    {
        return 0;
    }
    int maxArea = 0, area, m = grid.size(), n = grid[0].size();
    stack<pair<int, int>> s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                area = 1;
                s.push(pair<int, int>{i, j});
                while(!s.empty())
                {
                    pair<int, int> t = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int x = t.first + d[k], y = t.second + d[k + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            grid[x][y] = 0;
                            area++;
                            s.push(pair<int, int>{x, y});
                        }
                    }
                }
                maxArea = max(maxArea, area);
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