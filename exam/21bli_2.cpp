#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_set<int>> row;
unordered_map<int, unordered_set<int>> col;
int main()
{
    int n, r, c, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> r >> c;
        row[r].insert(c);
        col[c].insert(r);
    }
    for (auto& p : row)
    {
        ans = max(ans, (int)p.second.size());
    }
    for (auto& p : col)
    {
        ans = max(ans, (int)p.second.size());
    }
    cout << ans << endl;
    return 0;
}
