#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size(), pre = s[0] - '0';
        if (n == 1)
        {
            return 1;
        }
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            int cur = s[i - 1] - '0';
            if (pre == 1 || pre == 2 && cur <= 5)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
            pre = cur;
        }
        return dp[n];
    }
};
