#include<bits/stdc++.h>
using namespace std;
// 3.0
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans;
    for (int num:nums)
    {
        m[num]++;
    }
    for (auto p:m)
    {
        pq.push(pair<int, int>{p.second, p.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
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