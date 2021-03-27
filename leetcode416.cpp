#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    if (sum % 2)
    {
        return false;
    }
    sum /= 2;
    vector<bool> dp(sum, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= nums[i - 1]; j--)
        {
            dp[j] = dp[j] || dp[j - nums[i - 1]];
            if (dp[sum])
            {
                return true;
            }
        }
    }
    return false;
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
    cout << canPartition(nums) << endl;
    return 0;
}