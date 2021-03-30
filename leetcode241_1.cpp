#include<bits/stdc++.h>
using namespace std;
vector<int> diffWaysToCompute(string expression) {
    vector<int> ans;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int& l : left)
            {
                for (int& r : right)
                {
                    switch (c)
                    {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    if (ans.empty())
    {
        ans.push_back(stoi(expression));
    }
    return ans;
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