#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size(), n = land[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int x = i, y = j;
                    while (x < m && land[x][j] == 1)
                    {
                        x++;
                    }
                    while (y < n && land[i][y] == 1)
                    {
                        y++;
                    }
                    for (int u = i; u < x; u++)
                    {
                        for (int v = j; v < y; v++)
                        {
                            land[u][v] = 0;
                        }
                    }
                    ans.push_back({i, j, x - 1, y - 1});
                }
            }
        }
        return ans;
    }
};
