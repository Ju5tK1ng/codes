#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                ans[i] = nums[i / 2];
            }
            else
            {
                ans[i] = nums[nums.size() - i / 2 - 1];
            }
        }
        return ans;
    }
};