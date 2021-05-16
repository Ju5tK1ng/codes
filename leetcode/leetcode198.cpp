#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    vector<int> ans(nums.size() + 1);
    ans[0] = 0;
    ans[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++)
    {
        ans[i] = max(ans[i - 1], ans[i - 2] + nums[i - 1]);
    }
    return ans[nums.size()];
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
    cout <<rob(nums) << endl;
    return 0;
}