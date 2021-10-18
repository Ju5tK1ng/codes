#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 1)
        {
            return n;
        }
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return c;
    }
};
