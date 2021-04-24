#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t;
        for (int i = 0; i < 1 << n; i++)
        {
            t.clear();
            for (int j = 0; j < n; j++)
            {
                if (i & 1 << j)
                {
                    t.push_back(nums[j]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), size;
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        for (int i = 0; i < n; i++)
        {
            size = ans.size();
            for (int j = 0; j < size; j++)
            {
                t = ans[j];
                t.push_back(nums[i]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};