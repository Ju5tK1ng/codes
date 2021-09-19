#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s2 = s;
        reverse(s.begin(), s.end());
        return s == s2;
    }
};

// 2.0
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        long long t = x, y = 0;
        while(t)
        {
            y = y * 10 + t % 10;
            t /= 10;
        }
        return x == y;
    }
};
