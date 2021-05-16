#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty())
    {
        return vector<int>{-1, -1};
    }
    int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (lower == nums.size() || nums[lower] != target)
    {
        return vector<int>{-1, -1};
    }
    return vector<int>{lower, upper};
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> target;
    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}