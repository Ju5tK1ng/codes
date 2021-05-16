#include<bits/stdc++.h>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (auto word : wordDict)
        {
            int len = word.size();
            if (i >= len && s.substr(i - len, len) == word && dp[i - len])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordDict[i];
    }
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}