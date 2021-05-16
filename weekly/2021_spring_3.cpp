#include<bits/stdc++.h>
using namespace std;
int magicTower(vector<int>& nums) {
    long long health = 1;
    int cnt = 0;
    int n = nums.size();
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q2;
    for (int i = 0; i < n; i++)
    {
        q.push(nums[i]);
    }
    while (cnt < n && !q.empty())
    {
        if (health + q.front() > 0)
        {
            health += q.front();
            if (q.front() < 0)
            {
                q2.push(q.front());
            }
            q.pop();
        }
        else
        {
            if (!q2.empty() && q2.top() < q.front())
            {
                health -= q2.top();
                q.push(q2.top());
                q2.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            cnt++;
        }     
    }
    return cnt == n ? -1 : cnt;
}

// 2.0
// int magicTower(vector<int>& nums) {
//     if (accumulate(nums.begin(), nums.end(), (long long)1) <= 0)
//     {
//         return -1;
//     }
//     long long health = 1;
//     int cnt = 0;
//     int n = nums.size();
//     priority_queue<int, vector<int>, greater<int>> q2;
//     for (int i = 0; i < n; i++)
//     {
//         health += nums[i];
//         if (nums[i] < 0)
//         {
//             q2.push(nums[i]);
//         }
//         if (health <= 0)
//         {
//             health -= q2.top();
//             q2.pop();
//             cnt++;
//         }
//     }
//     return cnt;
// }