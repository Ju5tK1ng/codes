#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0, maxi = 0, mini = nums.size() - 1;
        vector<int> cnt(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                ans++;
            }
            if (nums[i] > nums[maxi])
            {
                maxi = i;
                cnt[i]++;
            }
            else if(nums[i] == nums[maxi])
            {
                cnt[maxi]--;
            }
        }
        for (int i = nums.size() - 2; i > 0; i--)
        {
            if (nums[i] < nums[mini])
            {
                mini = i;
                cnt[i]++;
                if (cnt[i] == 2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
