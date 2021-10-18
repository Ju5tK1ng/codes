#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]))
            {
                ans[0] = m[target - nums[i]];
                ans[1] = i;
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
