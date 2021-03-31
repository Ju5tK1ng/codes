#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> sums;
public:
    Solution(vector<int>& w) {
        sums = move(w);
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    
    int pickIndex() {
        double pos = rand() * 1.0 / RAND_MAX * sums.back();
        return upper_bound(sums.begin(), sums.end(), floor(pos)) - sums.begin();
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
    for (int i = 0; i < 10; i++)
    {
        cout << obj->pickIndex();
        if (i != 9)
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