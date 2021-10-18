#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = 0, dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int& coin : coins)
        {
            for (int i = 1; i <= amount; i++)
            {
                if (i >= coin)
                {
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};
