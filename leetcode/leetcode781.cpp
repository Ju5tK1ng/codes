#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        int ans = 0;
        for (int& i : answers)
        {
            um[i]++;
        }
        for (auto& p : um)
        {
            ans += ((p.second - 1) / (p.first + 1) + 1) * (p.first + 1);
        }
        return ans;
    }
};

// 1.1
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        int ans = 0;
        for (int& i : answers)
        {
            if (um[i] > 0)
            {
                um[i]--;
            }
            else
            {
                um[i] = i;
                ans += i + 1;
            }
        }
        return ans;
    }
};

// 1.2
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int um[1000] = {0};
        int ans = 0;
        for (int& i : answers)
        {
            if (um[i] > 0)
            {
                um[i]--;
            }
            else
            {
                um[i] = i;
                ans += i + 1;
            }
        }
        return ans;
    }
};
