#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int ans, m, n, cnt;
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        // 终止条件
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            ans = max(ans, cnt);
            return;
        }
        // 改变值
        grid[i][j] = 0;
        cnt++;
        // 递归
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        ans = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1)
                {
                    cnt = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
