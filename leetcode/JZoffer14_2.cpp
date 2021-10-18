#include <bits/stdc++.h>
using namespace std;
// lc343
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
        {
            return n - 1;
        }
        const int MOD = 1e9 + 7;
        long long ans;
        if (n % 3 == 0)
        {
            ans = 1;
        }
        else if (n % 3 == 1)
        {
            n -= 4;
            ans = 4;
        }
        else
        {
            n -= 2;
            ans = 2;
        }
        while (n)
        {
            n -= 3;
            ans = ans * 3 % MOD;
        }
        return ans;
    }
};
