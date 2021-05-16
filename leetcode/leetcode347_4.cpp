#include<bits/stdc++.h>
using namespace std;
// 4.0
vector<int> quick_sort_find(vector<vector<int>>& vs, int l, int r, int k)
{
    if (l >= r)
    {
        vector<int> ans;
        for (int i = l; i < vs.size(); i++)
        {
            ans.push_back(vs[i][0]);
        }
        return ans;
    }
    swap(vs[l], vs[l + (r - l) / 2]);
    int i = l, j = r;
    vector<int> pivot = vs[l];
    while (i < j)
    {
        while (i < j && pivot[1] <= vs[j][1])
        {
            j--;
        }
        vs[i] = vs[j];
        while (i < j && vs[i][1] <= pivot[1])
        {
            i++;
        }
        vs[j] = vs[i];
    }
    vs[i] = pivot;
    if (i == k)
    {
        vector<int> ans;
        for (; i < vs.size(); i++)
        {
            ans.push_back(vs[i][0]);
        }
        return ans;
    }
    else if (i > k)
    {
        return quick_sort_find(vs, l, i - 1, k);
    }
    else
    {
        return quick_sort_find(vs, i + 1, r, k);
    }
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<vector<int>> vs;
    for (int num:nums)
    {
        m[num]++;
    }
    for (auto p:m)
    {
        vs.push_back(vector<int>{p.first, p.second});
    }
    return quick_sort_find(vs, 0, vs.size() - 1, vs.size() - k);
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
    vector<int> ans = topKFrequent(nums, k);
    for (int i = 0; i < k; i++)
    {
        cout << ans[i];
        if (i != k - 1)
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