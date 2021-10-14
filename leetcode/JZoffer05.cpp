#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size() - 1, m = -1;
        for (char& c : s)
        {
            if (c == ' ')
            {
                m += 3;
            }
            else
            {
                m++;
            }
        }
        s.resize(m + 1);
        while (n != m)
        {
            if (s[n] == ' ')
            {
                s[m] = '0';
                s[m - 1] = '2';
                s[m - 2] = '%';
                m -= 3;
            }
            else
            {
                s[m] = s[n];
                m--;
            }
            n--;
        }
        return s;
    }
};
