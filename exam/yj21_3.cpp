#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> work(vector<int>& a, vector<int>& t, vector<int>& c, vector<int>& d) {
        int n = a.size(), m = c.size();
        vector<int> ans;
        set<int> sets[n];
        map<int, int> i2set;
        for (int i = 0; i < n; i++)
        {
            i2set[i] = i;
            sets[i2set[i]].insert(i);
        }
        for (int i = 0; i < m; i++)
        {
            if (t[i] == 0)
            {
                for (auto& i : sets[i2set[d[i]]])
                {
                    sets[i2set[c[i]]].insert(i);
                    i2set[i] = i2set[c[i]];
                }
            }
            else if (t[i] == 1)
            {
                for (auto& i : sets[i2set[c[i]]])
                {
                    a[i] += d[i];
                }
            }
            else
            {
                ans.push_back(a[c[i]]);
            }
        }
        return ans;
    }
};
