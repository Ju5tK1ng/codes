#include <bits/stdc++.h>
using namespace std;
struct Treenode
{
    int l, r, f;
};
Treenode a[100010];

int n, l, r;
pair<int, int> ans = make_pair(INT_MAX, INT_MAX);

int cal(int i, int deep)
{
    if (i == 0)
    {
        return 0;
    }
    int l = cal(a[i].l, deep + 1), r = cal(a[i].r, deep + 1);
    // cout << i << " " << l << " " << r << endl;
    if (l == -1 || r == -1 || abs(l - r) > 1)
    {
        return -1;
    }
    if (deep < ans.first || deep == ans.first && i < ans.second)
    {
        ans = make_pair(deep, i);
    }
    return 1 + max(l, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        a[i].l = l;
        a[i].r = r;
        a[l].f = i;
        a[r].f = i;
    }
    cal(1, 1);
    cout << ans.second << endl;
    return 0;
}
