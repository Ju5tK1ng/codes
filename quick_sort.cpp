#include<bits/stdc++.h>
using namespace std;
// 左闭右闭
void quick_sort1(vector<int>& nums, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, pivot = nums[l];
        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        quick_sort1(nums, l, i - 1);
        quick_sort1(nums, i + 1, r);
    }
}
// 左闭右开
void quick_sort2(vector<int>& nums, int l, int r)
{
    if (l + 1 < r)
    {
        int i = l, j = r - 1, pivot = nums[l];
        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
            {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        quick_sort1(nums, l, i);
        quick_sort1(nums, i + 1, r);
    }
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
    quick_sort2(nums, 0, nums.size());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i];
        if (i != n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}