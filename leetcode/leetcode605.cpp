#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), {1, 0});
        flowerbed.insert(flowerbed.end(), {0, 1});
        int l = flowerbed.size(), flag = 0, ans = 0;
        for (int i = 1; i < l; i++)
        {
            if (flowerbed[i] == 1)
            {
                ans += (i - flag - 1) / 2;
                flag = i;
            }
        }
        return ans >= n;
    }
};
