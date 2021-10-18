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
        int ans;
        if (n % 3 == 0)
        {
            ans = pow(3, n / 3);
        }
        else if (n % 3 == 1)
        {
            ans = pow(3, n / 3 - 1) * 4;
        }
        else
        {
            ans = pow(3, n / 3) * 2;
        }
        return ans;
    }
};
