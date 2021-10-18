#include <bits/stdc++.h>
using namespace std;

void Solution(int length, int n)
{
    int dp[n + 1][length];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < length; j++)
        {
            dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length];
        }
    }
    cout << dp[n][0] << endl;
}

int main()
{
    for (int i = 2; i <= 20; i++)
    {
        Solution(10, i);
    }
    return 0;
}
