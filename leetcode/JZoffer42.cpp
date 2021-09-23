#include <bits/stdc++.h>
using namespace std;
// 同lc53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (int& i : nums)
        {
            sum += i;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};
