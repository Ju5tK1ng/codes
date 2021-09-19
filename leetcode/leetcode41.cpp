#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = nums.size();
        for (int& i : nums)
        {
            if (i <= 0)
            {
                i = l + 1;
            }
        }
        for (int& i : nums)
        {
            if (abs(i) <= l && nums[abs(i) - 1] > 0)
            {
                nums[abs(i) - 1] *= -1;
            }
        }
        for (int i = 0; i < l; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return l + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            while (i + 1 != nums[i] && nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 != nums[i])
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
