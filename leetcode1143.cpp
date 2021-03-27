#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // 1.1
    // int dp[m + 1][n + 1];
    // memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1, text2) << endl;
}