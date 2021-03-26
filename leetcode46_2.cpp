#include<bits/stdc++.h>
using namespace std;
// 2.0
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