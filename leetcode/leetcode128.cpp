#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (int& i : nums)
        {
            us.insert(i);
        }
        int ans = 0;
        for (int& i : nums)
        {
            if (!us.count(i - 1))
            {
                int tmp = i;
                while(us.count(tmp + 1))
                {
                    tmp++;
                }
                ans = max(ans, tmp - i + 1);
            }
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int ans = 1, cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            ans = max(ans, cnt + 1);
        }
        return ans;
    }
};
