#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteSpace(string& s, int& i)
    {
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
    }

    bool isInt(string& s, int& i)
    {
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        return isUInt(s, i);
    }

    bool isUInt (string& s, int& i)
    {
        int j = i;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            i++;
        }
        return i > j;
    }

    bool isNumber(string s) {
        int i = 0;
        deleteSpace(s, i);
        bool is = isInt(s, i);
        if (s[i] == '.')
        {
            i++;
            is |= isUInt(s, i);
        }
        if (s[i] == 'e' || s[i] == 'E')
        {
            i++;
            is &= isInt(s, i);
        }
        deleteSpace(s, i);
        return is && i == s.size();
    }
};
