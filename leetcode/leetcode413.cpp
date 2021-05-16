#include<bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
            ans += dp[i];
        }
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
    cout <<numberOfArithmeticSlices(nums) << endl;
    return 0;
}