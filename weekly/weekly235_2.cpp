#include<bits/stdc++.h>
using namespace std;
vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    map<int, unordered_set<int>> m;
    vector<int> ans(k, 0);
    for (auto& log : logs)
    {
        m[log[0]].insert(log[1]);
    }
    for (auto& is : m)
    {
        if (is.second.size() != 0)
        {
            ans[is.second.size() - 1]++;
        }
    }
    return ans;
}