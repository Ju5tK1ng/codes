#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j];
            if (j != n-1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
    return 0;
}