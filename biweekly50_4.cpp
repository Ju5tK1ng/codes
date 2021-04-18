#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int makeStringSorted(string s) {
        long long ans = 0, less, f = 1;
        int n = s.size();
        unordered_set<char> us;
        for (int i = n - 1; i >= 0; i--)
        {
            less = 0;
            if (i != n - 1)
            {
                f = (f * (n - i - 1)) % MOD;
            }
            for (const char& c : us)
            {
                if (c < s[i])
                {
                    less++;
                }
            }
            us.insert(s[i]);
            ans = (ans + (less * f)) % MOD;
        }
        return ans;
    }
};