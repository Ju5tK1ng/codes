#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0, m = mat.size(), n = mat[0].size();
        while (i < m && j < n)
        {
            while (i >= 0 && j < n)
            {
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if (j < n)
            {
                i++;
            }
            else
            {
                i += 2;
                j--;
            }
            while (i < m && j >= 0)
            {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if (i < m)
            {
                j++;
            }
            else
            {
                i--;
                j += 2;
            }
        }
        return ans;
    }
};
