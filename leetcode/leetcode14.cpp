#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = INT_MAX;
        for (auto& s : strs)
        {
            l = min(l, (int)s.size());
        }
        string ans;
        char c;
        for (int i = 0; i < l; i++)
        {
            c = strs[0][i];
            for (auto& s : strs)
            {
                if (c != s[i])
                {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};
