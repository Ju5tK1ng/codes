#include<bits/stdc++.h>
using namespace std;
// 2.0
vector<int> diffWaysToCompute(string expression) {
    vector<int> nums;
    vector<char> ops;
    int num;
    char op;
    istringstream ss(expression + '+');
    while (ss >> num >> op)
    {
        nums.push_back(num);
        ops.push_back(op);
    }
    int n = nums.size();
    vector<int> dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i].push_back(nums[i]);
    }
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i + k < n; i++)
        {
            for (int j = i; j < i + k; j++)
            {
                for (int l : dp[i][j])
                {
                    for (int r : dp[j + 1][i + k])
                    {
                        switch (ops[j])
                        {
                            case '+':
                                dp[i][i + k].push_back(l + r);
                                break;
                            case '-':
                                dp[i][i + k].push_back(l - r);
                                break;
                            case '*':
                                dp[i][i + k].push_back(l * r);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    string expression;
    cin >> expression;
    vector<int> ans = diffWaysToCompute(expression);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
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