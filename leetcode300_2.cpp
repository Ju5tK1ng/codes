#include<bits/stdc++.h>
using namespace std;
// 2.0
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (dp.back() < nums[i])
        {
            dp.push_back(nums[i]);
        }
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];
        }
    }
    return dp.size();
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
    cout << lengthOfLIS(nums) << endl;
    return 0;
}