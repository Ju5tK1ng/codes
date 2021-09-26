#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, short> um =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (um[s[i]] < um[s[i + 1]])
            {
                ans -= um[s[i]];
            }
            else
            {
                ans += um[s[i]];
            }
        }
        ans += um[s.back()];
        return ans;
    }
};

// 1.1
class Solution {
public:
    int romanToInt(string s) {
        short um[128];
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (um[s[i]] < um[s[i + 1]])
            {
                ans -= um[s[i]];
            }
            else
            {
                ans += um[s[i]];
            }
        }
        ans += um[s.back()];
        return ans;
    }
};
