#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char c : num)
        {
            while (ans.size() && k && ans.back() > c)
            {
                ans.pop_back();
                k--;
            }
            ans += c;
        }
        ans.resize(ans.size() - k);
        ans = "0" + ans;
        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0')
        {
            i++;
        }
        return ans.substr(i);
    }
};
