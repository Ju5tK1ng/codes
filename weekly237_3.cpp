#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0];
}
struct Comp
{
    bool operator() (vector<int>& a, vector<int>& b)
    {
        if (a[1] == b[1])
        {
            return a[2] > b[2];
        }
        return a[1] > b[1];
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long long n = tasks.size(), time = 0, cnt = 0;
        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, Comp> q;
        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), cmp);
        while (ans.size() < n)
        {
            if (q.empty() && time < tasks[cnt][0])
            {
                time = tasks[cnt][0];
            }
            while (cnt < n && time >= tasks[cnt][0])
            {
                q.push(tasks[cnt]);
                cnt++;
            }
            ans.push_back (q.top()[2]);
            time += q.top()[1];
            q.pop();
        }
        return ans;
    }
};