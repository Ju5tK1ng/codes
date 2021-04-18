#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0, a1 = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            a1 ^= arr1[i];
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            ans ^= a1 & arr2[i];
        }
        return ans;
    }
};