#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), cmp);
        long long ans = 0, i = 0;
        vector<long long> dp(rides.back()[1] + 1, 0);
        for (vector<int>& v : rides)
        {
            for (; i <= v[1]; i++)
            {
                dp[i] = max(dp[i], ans);
            }
            ans = dp[v[1]] = max(dp[v[1]], dp[v[0]] + v[1] - v[0] + v[2]);
        }
        return ans;
    }
};
