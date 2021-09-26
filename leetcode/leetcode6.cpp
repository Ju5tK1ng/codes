#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> v(numRows, "");
        int r = 0, d = 1;
        for (char& c : s)
        {
            v[r] += c;
            r += d;
            if (r == 0 || r == numRows - 1)
            {
                d *= -1;
            }
        }
        string ans;
        for (string& s : v)
        {
            ans += s;
        }
        return ans;
    }
};
