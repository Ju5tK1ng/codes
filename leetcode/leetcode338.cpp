#include<bits/stdc++.h>
using namespace std;
vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 1; i <= num; i++)
    {
        dp[i] = i & 1 ? dp[i - 1] + 1 : dp[i >> 1];
    }
    return dp;
}
int main()
{
    int num;
    cin >> num;
    vector<int> ans = countBits(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        i == ans.size() - 1 ? cout << endl : cout << ' ';
    }
    return 0;
}