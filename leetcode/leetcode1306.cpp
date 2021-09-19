#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> used(n, false);
        q.push(start);
        used[start] = true;
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            if (arr[i] == 0)
            {
                return true;
            }
            if (i + arr[i] < n && !used[i + arr[i]])
            {
                q.push(i + arr[i]);
                used[i + arr[i]] = true;
            }
            if (i - arr[i] >= 0 && !used[i - arr[i]])
            {
                q.push(i - arr[i]);
                used[i - arr[i]] = true;
            }
        }
        return false;
    }
};
