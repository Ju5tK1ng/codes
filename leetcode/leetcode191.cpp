#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n)
        {
            n &= n - 1;
            ans++;
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + (n >> 1 & 0x55555555);
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
        n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
        return n;
    }
};
