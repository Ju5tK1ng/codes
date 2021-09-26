#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), sum = INT_MIN;
        vector<int> ans;
        vector<int> colSum(n);
        for (int t = 0; t < m; t++)
        {
            fill(colSum.begin(), colSum.end(), 0);
            for (int b = t; b < m; b++)
            {
                int curSum = 0, mini = 0, minSum = 0;
                for (int i = 0; i < n; i++)
                {
                    colSum[i] += matrix[b][i];
                    curSum += colSum[i];
                    if (curSum - minSum > sum)
                    {
                        sum = curSum - minSum;
                        ans = {t, mini, b - 1, i};
                    }
                    if (curSum < minSum)
                    {
                        minSum = curSum;
                        mini = i + 1;
                    }
                }
            }
        }
        return ans;
    }
};

// 2.1  数组遍历比vector快
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), sum = INT_MIN;
        // matrix.insert(matrix.begin(), vector<int>(n, 0));
        int preSum[m + 1][n];
        memset(preSum, 0, sizeof(preSum));
        vector<int> ans;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // matrix[i][j] += matrix[i - 1][j];
                preSum[i][j] = preSum[i - 1][j] + matrix[i - 1][j];
            }
        }
        for (int t = 0; t < m; t++)
        {
            for (int b = t + 1; b <= m; b++)
            {
                int curSum = 0, mini = 0, minSum = 0;
                for (int i = 0; i < n; i++)
                {
                    // curSum += matrix[b][i] - matrix[t][i];
                    curSum += preSum[b][i] - preSum[t][i];
                    if (curSum - minSum > sum)
                    {
                        sum = curSum - minSum;
                        ans = {t, mini, b - 1, i};
                    }
                    if (curSum < minSum)
                    {
                        minSum = curSum;
                        mini = i + 1;
                    }
                }
            }
        }
        return ans;
    }
};
