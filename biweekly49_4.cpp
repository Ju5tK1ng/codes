#include<bits/stdc++.h>
using namespace std;
int dp[40][9];
int maxHappyGroups(int batchSize, vector<int>& groups) {
    set<int> ans;
    for (int i = 0; i < groups.size(); i++)
    {
        for (int j = 0; j < batchSize; j++)
        {
            if (j == 0 || dp[i][(j + groups[i]) % batchSize] != 0 || dp[i][j] != 0)
            {
                dp[i + 1][(j + groups[i]) % batchSize] = max(dp[i][(j + groups[i]) % batchSize], dp[i][j] + groups[i]);
            }
        }
        if (dp[i][0] != 0)
        {
            ans.insert(dp[i][0]);
        }
    }
    int sum = accumulate(groups.begin(), groups.end(), 0);
    if (sum % batchSize)
    {
        return ans.size();
    }
    return ans.size() - 1;
}