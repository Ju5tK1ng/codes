// 1.1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int dp[len + 1], ans = 1, prepre = 0, pre = 0;
        dp[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            if (s[i - 1] == 'N')
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                prepre = pre;
                pre = i;
                dp[i] = 0;
            }
            if (pre == 0)
            {
                ans = max(ans, dp[i]);
            }
            else if (prepre == 0)
            {
                ans = max(ans, dp[i] + dp[pre - 1] + 1);
            }
            else
            {
                ans = max(ans, dp[i] + dp[pre - 1] + dp[prepre - 1] + 2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}