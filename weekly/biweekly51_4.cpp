#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> ans;
    set<int> s;
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = rooms.size(), n = queries.size();
        ans.resize(n, -1);
        for (int i = 0; i < m; i++)
        {
            swap(rooms[i][0], rooms[i][1]);
        }
        for (int i = 0; i < n; i++)
        {
            swap(queries[i][0], queries[i][1]);
            queries[i].push_back(i);
        }
        sort(rooms.begin(), rooms.end());
        reverse(rooms.begin(), rooms.end());
        sort(queries.begin(), queries.end());
        reverse(queries.begin(), queries.end());
        for (int i = 0, j = 0; i < n; i++)
        {
            int t = queries[i][2];
            for (; j < m && rooms[j][0] >= queries[i][0]; j++)
            {
                s.insert(rooms[j][1]);
            }
            auto it = s.lower_bound(queries[i][1]);
            if (it != s.end())
            {
                ans[t] = *it;
            }
            if (it != s.begin())
            {
                it--;
                if (ans[t] == -1 || queries[i][1] - *it <= ans[t] - queries[i][1])
                {
                    ans[t] = *it;
                }
            }
        }
        return ans;
    }
};