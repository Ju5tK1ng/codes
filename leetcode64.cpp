#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[1] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j] = min(dp[j - 1] + grid[i - 1][j - 1], dp[j] + grid[i - 1][j - 1]);
        }
    }
    return dp[n];
}
// 1.1
// int minPathSum(vector<vector<int>>& grid) {
//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             if (i == 0 && j != 0)
//             {
//                 grid[i][j] += grid[i][j - 1];
//             }
//             else if (i != 0 && j == 0)
//             {
//                 grid[i][j] += grid[i - 1][j];
//             }
//             else if (i != 0 && j != 0)
//             {
//                 grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
//             }
//         }
//     }
//     return grid[grid.size() - 1][grid[0].size() - 1];
// }
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        grid.push_back(v);
    }
    cout << minPathSum(grid) << endl;
    return 0;
}