#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceDigits(string s) {
        char pre = s[0];
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                pre = s[i];
            }
            else
            {
                s[i] = pre + s[i] - '0';
            }
        }
        return s;
    }
};