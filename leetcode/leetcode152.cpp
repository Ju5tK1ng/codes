#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, pro = 1, pre = 1;
        for (int& i : nums)
        {
            pro *= i;
            if (pre > 0)
            {
                pre *= i;
            }
            ans = max(ans, pro);
            if (pro != pre || i == 1)
            {
                ans = max(ans, pro / pre);
            }
            if (pro == 0)
            {
                pro = 1;
                pre = 1;
            }
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, maxn = 1, minn = 1;
        for (int& i : nums)
        {
            if (i < 0)
            {
                swap(maxn, minn);
            }
            maxn = max(maxn * i, i);
            minn = min(minn * i, i);
            ans = max(ans, maxn);
        }
        return ans;
    }
};
