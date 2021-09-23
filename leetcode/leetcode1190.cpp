#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        auto ite = s.begin();
        vector<string::iterator> ites;
        for (char& c : s)
        {
            if (c == '(')
            {
                ites.push_back(ite);
            }
            else if (c == ')')
            {
                reverse(ites.back(), ite);
                ites.pop_back();
            }
            else
            {
                *ite++ = c;
            }
        }
        s.erase(ite, s.end());
        return s;
    }
};
