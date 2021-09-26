#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = 1;
        int ans = 0, pre = 0;
        for (int& i : nums)
        {
            pre += i;
            if (um.count(pre - k))
            {
                ans += um[pre - k];
            }
            um[pre]++;
        }
        return ans;
    }
};
