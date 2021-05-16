#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    while(l <= r)
    {
        m = l + (r - l) / 2;
        if (nums[m] == target)
        {
            return true;
        }
        if (nums[m] == nums[l])
        {
            l++;
        }
        else if (nums[m] < nums[l])
        {
            if (nums[m] < target && target <= nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        else if (nums[m] > nums[l])
        {
            if (nums[l] <= target && target <= nums[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
    }
    return false;
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
    cout << search(nums, target) << endl;
    return 0;
}