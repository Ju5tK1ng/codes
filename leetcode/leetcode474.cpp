#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> count(string& str)
    {
        int c0 = 0, c1 = 0;
        for (char c : str)
        {
            if (c == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        return pair<int, int>{c0, c1};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (string& str : strs)
        {
            auto t = count(str);
            for (int i = m; i >= t.first; i--)
            {
                for (int j = n; j >= t.second; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - t.first][j - t.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
