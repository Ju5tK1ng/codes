#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(string s) {
        int cnt[1 << 12], n = s.size();
        bool ok[1 << 12];
        for (int i = 1; i < 1 << n; i++)
        {
            cnt[i] = cnt[i >> 1] + (i & 1);
            string str;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    str += s[j];
                }
            }
            string rev = str;
            reverse(rev.begin(), rev.end());
            ok[i] = str == rev;
        }
        int mask, ans = 0;
        for (int i = 1; i < 1 << n; i++)
        {
            if (ok[i])
            {
                for (int j = mask = (1 << n) - 1 ^ i; j > 0; j = j - 1 & mask)
                {
                    if (ok[j])
                    {
                        ans = max(ans, cnt[i] * cnt[j]);
                    }
                }
            }
        }
        return ans;
    }
};
