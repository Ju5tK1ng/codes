#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& t, int target, int i, int n)
    {
        if (target == 0)
        {
            ans.push_back(t);
        }
        if (i == n || target < 0)
        {
            return;
        }
        for (; i < candidates.size(); i++)
        {
            t.push_back(candidates[i]);
            dfs(candidates, ans, t, target - candidates[i], i, n);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = upper_bound(candidates.begin(), candidates.end(), target) - candidates.begin();
        vector<vector<int>> ans;
        vector<int> t;
        dfs(candidates, ans, t, target, 0, n);
        return ans;
    }
};