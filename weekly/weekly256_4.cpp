#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;
        long ans = 0;
        vector<int> dp{0, 1};
        for (char c : binary)
        {
            int t = c - '0';
            ans = (ans + dp[t]) % MOD;
            dp[t ^ 1] = (dp[t ^ 1] + dp[t]) % MOD;
        }
        if (binary != string(binary.size(), '1'))
        {
            ans++;
        }
        return ans % MOD;
    }
};
