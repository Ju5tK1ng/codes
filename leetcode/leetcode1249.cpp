#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        vector<int> cnt;
        for (char& c : s)
        {
            if (c == '(')
            {
                ans += c;
                cnt.push_back(ans.size() - 1);
            }
            else if (c == ')')
            {
                if (!cnt.empty())
                {
                    ans += c;
                    cnt.pop_back();
                }
            }
            else
            {
                ans += c;
            }
        }
        for (int i = cnt.size() - 1; i >= 0; i--)
        {
            ans.erase(cnt[i], 1);
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i = 0, l = 0, r = count(s.begin(), s.end(), ')');
        for (char& c : s)
        {
            if (c == '(')
            {
                if (r > 0)
                {
                    s[i++] = c;
                    l++;
                    r--;
                }
            }
            else if (c == ')')
            {
                if (l > 0)
                {
                    s[i++] = c;
                    l--;
                }
                else
                {
                    r--;
                }
            }
            else
            {
                s[i++] = c;
            }
        }
        s.erase(i);
        return s;
    }
};
