#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (!st.empty())
            {
                s[i] = '0';
                s[st.top()] = '0';
                st.pop();
            }
        }
        int pre = -1, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                ans = max(ans, i - pre - 1);
                pre = i;
            }
        }
        ans = max(ans, (int)s.size() - pre - 1);
        return ans;
    }
};
