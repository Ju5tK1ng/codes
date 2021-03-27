#include<bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else
            {
                int modify = 1;
                if (word1[i - 1] == word2[j - 1])
                {
                    modify = 0;
                }
                dp[i][j] = min(dp[i -1][j - 1] + modify, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
}