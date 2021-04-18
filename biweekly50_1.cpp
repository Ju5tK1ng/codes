#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (pre < nums[i])
            {
                pre = nums[i];
            }
            else
            {
                ans += pre + 1 - nums[i];
                pre++;
            }
        }
        return ans;
    }
};