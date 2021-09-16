#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), l, r;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
                else
                {
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    l++;
                    while (l < r - 1 && nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};

// 1.1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        auto begin = nums.begin(), end = nums.end();
        for (; begin != end; begin++)
        {
            if (*begin > 0)
            {
                break;
            }
            if (begin != nums.begin() && *prev(begin, 1) == *begin)
            {
                continue;
            }
            auto l = begin + 1;
            auto r = end - 1;
            while (l < r)
            {
                if (*begin + *l + *r < 0)
                {
                    l++;
                }
                else if (*begin + *l + *r > 0)
                {
                    r--;
                }
                else
                {
                    ans.push_back(vector<int>{*begin, *l, *r});
                    while (l + 1 < r && *l == *(l + 1))
                    {
                        l++;
                    }
                    l++;
                    while (l < r - 1 && *r == *(r - 1))
                    {
                        r--;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};
