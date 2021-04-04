#include<bits/stdc++.h>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (int& num : nums)
    {
        int pos = abs(num) - 1;
        if (nums[pos] > 0)
        {
            nums[pos] = -nums[pos];
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans.push_back(i + 1);
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
    vector<int> ans = findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        i == ans.size() - 1 ? cout << endl : cout << ' ';
    }
    return 0;
}