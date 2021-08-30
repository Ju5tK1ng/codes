#include <bits/stdc++.h>
using namespace std;
// time: nlogk;     space: n;
class Solution {
public:
    struct cmp
    {
        bool operator() (const string& a, const string& b)
        {
            if (a.size() != b.size())
            {
                return a.size() > b.size();
            }
            return a > b;
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;
        for (string num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};
