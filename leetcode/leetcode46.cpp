#include<bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int level, int n)
    {
        if (level == n - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < n; i++)
        {
            swap(nums[i], nums[level]);
            dfs(nums, ans, level + 1, n);
            swap(nums[i], nums[level]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        dfs(nums, ans, 0, n);
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
        {
            ans.push_back(nums);
        }
        return ans;
    }
};
