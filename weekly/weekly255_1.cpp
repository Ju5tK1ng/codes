#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(*nums.rbegin(), *nums.begin());
    }
};

// 2.0
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return __gcd(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
    }
};
