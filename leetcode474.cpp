#include<bits/stdc++.h>
using namespace std;
pair<int, int> count(string& str)
{
    int c0 = 0, c1 = 0;
    for (char c : str)
    {
        if (c == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
    }
    return pair<int, int>{c0, c1};
}
int findMaxForm(vector<string>& strs, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (string& str : strs)
    {
        auto t = count(str);
        for (int i = m; i >= t.first; i--)
        {
            for (int j = n; j >= t.second; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - t.first][j - t.second] + 1);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    int m, n, l;
    cin >> m >> n >> l;
    vector<string> strs(l);
    for (int i = 0; i < l; i++)
    {
        cin >> strs[i];
    }
    cout << findMaxForm(strs, m, n) << endl;
    return 0;
}