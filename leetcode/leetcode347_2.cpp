#include<bits/stdc++.h>
using namespace std;
// 2.0
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<int> ans;
    int maxcnt = 0;
    for (int num:nums)
    {
        maxcnt = max(maxcnt, ++m[num]);
    }
    vector<vector<int>> buckets(maxcnt + 1);
    for (auto p:m)
    {
        buckets[p.second].push_back(p.first);
    }
    for (int i = maxcnt; i >= 0 && ans.size() < k; i--)
    {
        for (int num:buckets[i])
        {
            ans.push_back(num);
        }
    }
    return ans;
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