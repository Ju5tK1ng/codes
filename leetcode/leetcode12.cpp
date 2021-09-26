#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    string intToRoman(int num) {
        map<short, string> um =
        {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        string ans;
        for (auto ite = um.rbegin(); ite != um.rend(); ite++)
        {
            while (num >= ite->first)
            {
                ans += ite->second;
                num -= ite->first;
            }
        }
        return ans;
    }
};

// 1.1
class Solution {
public:
    string intToRoman(int num) {
        int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i = 0; i < 13; i++)
        {
            while(num >= v[i])
            {
                ans += s[i];
                num -= v[i];
            }
        }
        return ans;
    }
};
