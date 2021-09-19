#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxr = 0, i = 0;
        while (i < n)
        {
            int t = maxr;
            if (maxr >= n - 1)
            {
                return ans;
            }
            for (; i <= t; i++)
            {
                maxr = max(maxr, i + nums[i]);
            }
            ans++;
        }
        return ans;
    }
};
