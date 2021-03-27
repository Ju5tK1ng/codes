#include<bits/stdc++.h>
using namespace std;
// 1.1
int maximalSquare(vector<vector<char>>& matrix) {
    int m  = matrix.size(), n = matrix[0].size(), ans = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = matrix[i][j] - '0';
            if (i != 0 && j != 0 && dp[i][j] == 1)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans * ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<char> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        matrix.push_back(v);
    }
    cout << maximalSquare(matrix) << endl;
    return 0;
}