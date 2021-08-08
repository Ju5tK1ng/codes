#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        for (auto word : words)
        {
            for (int j = 0; j < word.size(); j++)
            {
                if (s[i++] != word[j])
                {
                    return false;
                }
                if (i == s.size() && j == word.size() - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};