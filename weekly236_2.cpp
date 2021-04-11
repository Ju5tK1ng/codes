#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        int index = 0;
        while (v.size() != 1)
        {
            index = (index + k - 1) % v.size();
            v.erase(v.begin() + index);
        }
        return v[0];
    }
};

// 2.0
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};