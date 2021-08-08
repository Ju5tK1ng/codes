#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num:nums)
    {
        pq.push(num);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

// 1.1
// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int num:nums)
//     {
//         if (pq.size() <= k || pq.top() < num)
//         {
//             pq.push(num);
//             if (pq.size() > k)
//             {
//                 pq.pop();
//             }   
//         }
//     }
//     return pq.top();
// }

int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> k;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}