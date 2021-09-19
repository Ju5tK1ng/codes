#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2)
        {
            return {};
        }
        sort(changed.begin(), changed.end());
        vector<int> ans;
        for (int i = 0 ; i < changed.size(); i++)
        {
            if (changed[i] >= 0)
            {
                auto ite = lower_bound(changed.begin() + i + 1, changed.end(), changed[i] * 2);
                if (ite != changed.end() && *ite == changed[i] * 2)
                {
                    ans.push_back(changed[i]);
                    *ite = -1;
                }
                else
                {
                    return {};
                }
            }
        }
        return ans;
    }
};
