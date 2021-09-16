#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int ans = 0, mina = INT_MIN / 10, maxa = INT_MAX / 10;
        while (x)
        {
            if (ans < mina || ans > maxa)
            {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
