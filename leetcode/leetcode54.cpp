#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0;
        vector<int> ans;
        ans.push_back(matrix[i][j]);
        matrix[i][j] = INT_MIN;
        while (ans.size() != m * n)
        {
            while (j + 1 < n && matrix[i][j + 1] != INT_MIN)
            {
                j++;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
            }
            while (i + 1 < m && matrix[i + 1][j] != INT_MIN)
            {
                i++;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
            }
            while (j - 1 >= 0 && matrix[i][j - 1] != INT_MIN)
            {
                j--;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
            }
            while (i - 1 >= 0 && matrix[i - 1][j] != INT_MIN)
            {
                i--;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;
            }
        }
        return ans;
    }
};