#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, ans = INT_MAX;
        while (j < nums.size())
        {
            sum += nums[j];
            j++;
            while (sum >= target)
            {
                ans = min(ans, j - i);
                sum -= nums[i];
                i++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
