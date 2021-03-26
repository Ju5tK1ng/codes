#include<bits/stdc++.h>
using namespace std;
// 1.1
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    vector<vector<int>> vs;
    vector<int> ans(k);
    for (int num:nums)
    {
        m[num]++;
    }
    for (auto p:m)
    {
        vs.push_back(vector<int>{p.first, p.second});
    }
    sort(vs.begin(), vs.end(), [](const auto& a, const auto& b)
    {
        return a[1] > b[1];
    });
    for (int i = 0; i < k; i++)
    {
        ans[i] = vs[i][0];
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