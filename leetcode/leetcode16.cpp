#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minans = INT_MAX, ans;
        for (auto ite = nums.begin(); ite != nums.end(); ite++)
        {
            if (*ite > target)
            {
                break;
            }
            auto l = ite + 1;
            auto r = nums.end() - 1;
            while (l < r)
            {
                int cur = *ite + *l + *r;
                if (abs(cur - target) < minans)
                {
                    minans = abs(cur - target);
                    ans = cur;
                }
                if (cur < target)
                {
                    l++;
                }
                else if (cur > target)
                {
                    r--;
                }
                else
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};
