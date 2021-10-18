#include <bits/stdc++.h>
using namespace std;
// lc70
class Solution {
public:
    int numWays(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 1)
        {
            return 1;
        }
        int a = 1, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return c;
    }
};
