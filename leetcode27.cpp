#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        for (int& num : nums)
        {
            if (num != val)
            {
                nums[ans++] = num;
            }
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        for (int i = 0; i <= j; i++)
        {
            if (nums[i] == val)
            {
                swap(nums[i--], nums[j--]);
            }
        }
        return j + 1;
    }
};