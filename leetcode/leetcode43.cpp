#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int n = num1.size(), m = num2.size();
        vector<int> ansv(n + m, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                ansv[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = n + m - 1; i > 0; i--)
        {
            ansv[i - 1] += ansv[i] / 10;
            ansv[i] %= 10;
        }
        int start = 0;
        if (ansv[0] == 0)
        {
            start++;
        }
        string ans;
        for (int i = start; i < n + m; i++)
        {
            ans += ansv[i] + '0';
        }
        return ans;
    }
};
