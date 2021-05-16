#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int C(long num)
{
    if (num < 2)
    {
        return 0;
    }
    return ((num % mod) * ((num - 1) % mod) / 2) % mod;
}

int countNicePairs(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> m;
    for (int num : nums)
    {
        int t = num, rev = 0;
        while (t)
        {
            rev = rev * 10 + t % 10;
            t /= 10;
        }
        m[num - rev]++;
    }
    for (auto num : m)
    {
        ans = (ans + C(num.second)) % mod;
    }
    return ans;
}