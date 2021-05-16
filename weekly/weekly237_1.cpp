#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int a[128];
        memset(a, 0, sizeof(a));
        int ans = 0;
        for (char& c : sentence)
        {
            if (a[c] == 0)
            {
                a[c] = 1;
                ans++;
            }
        }
        if (ans == 26)
        {
            return true;
        }
        return false;
    }
};