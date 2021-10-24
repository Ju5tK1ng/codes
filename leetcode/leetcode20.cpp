#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for (char& c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                sc.push(c);
            }
            else
            {
                if (!sc.empty() && (
                    sc.top() == '(' && c == ')' ||
                    sc.top() == '[' && c == ']' ||
                    sc.top() == '{' && c == '}'))
                {
                    sc.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return sc.empty();
    }
};
