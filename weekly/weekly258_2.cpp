#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        vector<long long> v = {0, 0};
        unordered_map<double, int> m;
        int maxn = 0;
        for (auto& v : rectangles)
        {
            m[(double)v.front() / v.back()]++;
            maxn = max(maxn, m[(double)v.front() / v.back()]);
        }
        for (long long i = 2; i <= maxn; i++)
        {
            v.push_back(v[i - 1] + i - 1);
        }
        long long ans = 0;
        for (auto& p : m)
        {
            ans += v[p.second];
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> m;
        long long ans = 0;
        for (auto& v : rectangles)
        {
            ans += m[(double)v.front() / v.back()]++;
        }
        return ans;
    }
};
