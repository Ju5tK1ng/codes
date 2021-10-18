#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        nums.push_back(INT_MIN);
        while (l < r)
        {
            int m = l + (r - l + 1) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            {
                return m;
            }
            else if (nums[m] > nums[m - 1])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};
