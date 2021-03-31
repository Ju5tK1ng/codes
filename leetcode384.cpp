#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = move(nums);
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(origin);
        for (int i = shuffled.size() - 1; i >= 0; i--)
        {
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        return shuffled;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution* obj = new Solution(nums);
    vector<int> ans1 = obj->reset();
    vector<int> ans2 = obj->shuffle();
    for (int i = 0; i < n; i++)
    {
        cout << ans1[i];
        if (i != n -1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans2[i];
        if (i != n -1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}