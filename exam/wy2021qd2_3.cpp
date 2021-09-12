#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int dp[s.size() + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = dp[1];
    if (s[0] == '1')
    {
        dp[2] += dp[0];
    }
    for (int i = 3; i <= s.size(); i++)
    {
        dp[i] = dp[i - 1];
        if (s[i - 3] == '1')
        {
            dp[i] += dp[i - 3];
        }
        if (s[i - 2] == '1')
        {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[s.size()] << endl;
    return 0;
}
