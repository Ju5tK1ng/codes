#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>> pq;
        for (auto pile : piles)
        {
            pq.push(pile);
        }
        while (k--)
        {
            pq.push((pq.top() - 1) / 2 + 1);
            pq.pop();
        }
        int ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};