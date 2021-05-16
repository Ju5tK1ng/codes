#include<bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && T[s.top()] < T[i])
        {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    vector<int> ans = dailyTemperatures(T);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (n != i - 1)
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