#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSub(string& s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int l = 0, len = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int tlen = countSub(s, i, i);
            tlen = max(tlen, countSub(s, i, i + 1));
            if (tlen > len)
            {
                l = i - (tlen - 1) / 2;
                len = tlen;
            }
        }
        return s.substr(l, len);
    }
};

// 2.0
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }
        string r = s;
        reverse(r.begin(), r.end());
        int dp[n + 1][n + 1], l = 0, len = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == r[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (len < dp[i][j])
                {
                    if (i - dp[i][j] == n - j)
                    {
                        l = i - dp[i][j];
                        len = dp[i][j];
                    }
                }
            }
        }
        return s.substr(l, len);
    }
};