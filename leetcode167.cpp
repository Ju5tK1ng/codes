#include<bits/stdc++.h>
using namespace std;
// 1.1
vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0, end = numbers.size() - 1;
    while (numbers[start] + numbers[end] != target)
    {
        if (numbers[start] + numbers[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return vector<int>{start + 1, end + 1};
}
int main()
{
    int n, t, target;
    vector<int> numbers;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        numbers.push_back(t);
    }
    cin >> target;
    vector<int> ans = twoSum(numbers, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}