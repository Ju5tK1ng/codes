#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2, j = i + 1, k = i + 1;
        while (i >= 0 && nums[i] >= nums[j])
        {
            i--;
            j--;
        }
        if (i >= 0)
        {
            while (nums[i] >= nums[k])
            {
                k--;
            }
            swap(nums[i], nums[k]);
        }
        reverse(nums.begin() + j, nums.end());
    }
};
