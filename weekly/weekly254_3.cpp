#include<bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    int minNonZeroProduct(int p) {
        const long MOD = 1e9 + 7;
        long ans, length, res;
        length = (long)1 << p;
        ans = length - 1;
        res = length - 2;
        for (long i = 1; i < length / 2; i *= 2)
        {
            ans = (ans % MOD) * (res % MOD);
            res = (res % MOD) * (res % MOD);
        }
        return ans % MOD;
    }
};

// 2.0
class Solution {
public:
    const long MOD = 1e9 + 7;

    long quick_pow(long x, long y)
    {
        long res = 1;
        while (y)
        {
            if (y & 1)
            {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    int minNonZeroProduct(int p) {
        long ans, length;
        length = (long)1 << p;
        ans = quick_pow((length - 2) % MOD, (length - 1) / 2);
        ans = ans * ((length - 1) % MOD);
        return ans % MOD;
    }
};