#include <bits/stdc++.h>
using namespace std;
// lc50
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        for (int i = n; i != 0; i /= 2)
        {
            if (i & 1)
            {
                ans *= x;
            }
            x *= x;
        }
        if (n < 0)
        {
            ans = 1 / ans;
        }
        return ans;
    }
};
