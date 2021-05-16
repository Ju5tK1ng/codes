#include<bits/stdc++.h>
using namespace std;
// 2.0
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size(), dp[n + 1], pre, cur;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        pre = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++)
        {
            cur = dp[j];
            int modify = 1;
            if (word1[i - 1] == word2[j - 1])
            {
                modify = 0;
            }
            dp[j] = min(pre + modify, min(dp[j] + 1, dp[j - 1] + 1));
            pre = cur;
        }
    }
    return dp[n];
}
int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
}