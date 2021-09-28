#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26)
        {
            return false;
        }
        bitset<26> bs(0);
        for (char c : astr)
        {
            if (bs[c - 'a'])
            {
                return false;
            }
            bs[c - 'a'] = 1;
        }
        return true;
    }
};
