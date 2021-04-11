#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int ans = 0, pos = 0, cur1 = 2, cur2 = 2, n = obstacles.size();
        while (pos != n)
        {
            int preo = obstacles[pos], o = obstacles[pos + 1];
            if (o != cur1 && o != cur2)
            {
            }
            else if (cur1 == cur2)
            {
                ans++;
                cur1 = o % 3 + 1;
                cur2 = (o + 1) % 3 + 1;
                if (cur1 == preo)
                {
                    cur1 = cur2;
                }
                else if (cur2 == preo)
                {
                    cur2 = cur1;
                }
            }
            else if (o == cur1)
            {
                cur1 = cur2;
            }
            else if (o == cur2)
            {
                cur2 = cur1;
            }
            pos++;
        }
        return ans;
    }
};