#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i < (1 << n); i++)
        {
            int t = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    t ^= nums[j];
                }
            }
            ans += t;
        }
        return ans;
    }
};