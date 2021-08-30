#include <bits/stdc++.h>
using namespace std;
// time: n(2^n);    space: 2^n
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> dp(1 << n), sum(1 << n);
        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    sum[mask] = sum[mask ^ (1 << i)] + tasks[i];
                    break;
                }
            }
        }
        for (int mask = 1; mask < (1 << n); mask++)
        {
            dp[mask] = INT_MAX;
            for (int subMask = mask; subMask; subMask = (subMask - 1) & mask)
            {
                if (sum[subMask] <= sessionTime)
                {
                    dp[mask] = min(dp[mask], dp[subMask ^ mask] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
