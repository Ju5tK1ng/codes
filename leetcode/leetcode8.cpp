#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int n = s.size(), negative = 1, i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i < n && s[i] == '-')
        {
            negative = -1;
            i++;
        }
        else if (i < n && s[i] == '+')
        {
            negative = 1;
            i++;
        }
        for (; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                break;
            }
            ans = ans * 10 + negative * (s[i] - '0');
            if (ans > INT_MAX)
            {
                ans = INT_MAX;
                break;
            }
            else if (ans < INT_MIN)
            {
                ans = INT_MIN;
                break;
            }
        }
        return ans;
    }
};
