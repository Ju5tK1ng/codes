#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto& pattern : patterns)
        {
            if (word.find(pattern) < word.size())
            {
                cnt++;
            }
        }
        return cnt;
    }
};