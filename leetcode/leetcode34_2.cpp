#include<bits/stdc++.h>
using namespace std;
// 2.0
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty())
    {
        return vector<int>{-1, -1};
    }
    int l = 0, r = nums.size();
    while(l < r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    int lower = l;
    l = 0, r = nums.size();
    while(l < r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] <= target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    int upper = l - 1;
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