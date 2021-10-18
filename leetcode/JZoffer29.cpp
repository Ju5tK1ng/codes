#include <bits/stdc++.h>
using namespace std;
// lc54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
        {
            return ans;
        }
        int i = 0, j = -1, l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        while (l <= r && t <= b)
        {
            while (j < r)
            {
                j++;
                ans.push_back(matrix[i][j]);
            }
            t++;
            while (i < b)
            {
                i++;
                ans.push_back(matrix[i][j]);
            }
            r--;
            while (j > l && t <= b)
            {
                j--;
                ans.push_back(matrix[i][j]);
            }
            b--;
            while (i > t && l <= r)
            {
                i--;
                ans.push_back(matrix[i][j]);
            }
            l++;
        }
        return ans;
    }
};
