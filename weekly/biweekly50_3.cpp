#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), m = 1, cur = 0;
        vector<int> ans(n);
        while (maximumBit--)
        {
            m *= 2;
        }
        m--;
        for (int i = 0; i < n; i++)
        {
            cur ^= nums[i];
            ans[n - 1 - i] = m - cur;
        }
        return ans;
    }
};