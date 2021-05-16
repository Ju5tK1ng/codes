#include<bits/stdc++.h>
using namespace std;
class FindSumPairs {
    unordered_map<int, int> n2;
    vector<int> n1, n3;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n3 = nums2;
        for (int& num : nums2)
        {
            n2[num]++;
        }
    }
    
    void add(int index, int val) {
        n2[n3[index]]--;
        n3[index] += val;
        n2[n3[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < n1.size(); i++)
        {
            if (n2.count(tot - n1[i]))
            {
                cnt += n2[tot - n1[i]];
            }
        }
        return cnt;
    }
};