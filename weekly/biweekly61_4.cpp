#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1, index = 1, r, ans = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            r = nums[i] + n - 1;
            if (i > 0 && nums[i] != nums[i - 1])
            {
                cnt--;
            }
            for (; index < n && nums[index] <= r ; index++)
            {
                if (nums[index] != nums[index - 1])
                {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return n - ans;
    }
};
