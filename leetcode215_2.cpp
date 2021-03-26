#include<bits/stdc++.h>
using namespace std;
// 2.0
int quick_sort_find(vector<int>& nums, int l, int r, int k)
{
    if (l >= r)
    {
        return nums[l];
    }
    // 2.1
    // swap(nums[l], nums[l + (r - l) / 2]);
    // 2.2
    // swap(nums[l], nums[rand() % (r - l + 1) + l]);
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
    if (i == k)
    {
        return nums[i];
    }
    else if (i > k)
    {
        return quick_sort_find(nums, l, i - 1, k);
    }
    else
    {
        return quick_sort_find(nums, i + 1, r, k);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    // 2.2
    // srand(time(NULL));
    return quick_sort_find(nums, 0, nums.size() - 1, nums.size() - k);
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> k;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}