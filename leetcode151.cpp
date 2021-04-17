#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans, t;
        istringstream ss(s);
        ss >> ans;
        while (ss >> t)
        {
            ans = t + ' ' + ans;
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = 0, r, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (len != 0)
                {
                    s[len++] = ' ';
                }
                r = i;
                while (r < n && s[r] != ' ')
                {
                    s[len++] = s[r++];
                }
                reverse(s.begin() + len - (r - i), s.begin() + len);
                i = r;
            }
        }
        return s.substr(0, len);
    }
};