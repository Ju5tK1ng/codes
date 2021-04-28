#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int ans = 0;
        for (int& num : nums)
        {
            if (nums[ans] != num)
            {
                nums[++ans] = num;
            }
        }
        return ans + 1;
    }
};