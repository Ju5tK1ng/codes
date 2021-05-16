#include<bits/stdc++.h>
using namespace std;
// 1.1
void dfs(int n, int k, vector<vector<int>>& ans, vector<int>& a, int cnt, int pos)
{
    if (cnt + n - pos + 1 < k)
    {
        return;
    }
    if (cnt == k)
    {
        ans.push_back(a);
        return;
    }
    for (int i = pos; i <= n; i++)
    {
        a[cnt++] = i;
        dfs(n, k, ans, a, cnt, i + 1);
        cnt--;
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> a(k);
    dfs(n, k, ans, a, 0, 1);
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans = combine(n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << ans[i][j];
            if (j != k-1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
}