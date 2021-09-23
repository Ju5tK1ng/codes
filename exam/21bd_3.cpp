#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int main()
{
    int n, p, t, ans = 0;
    cin >> n >> p;
    cin >> t;
    a.push_back(t);
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        if (t != a[i - 1])
        {
            a.push_back(t);
        }
    }
    int i = 1;
    for (; i < a.size(); i++)
    {
        if (a[i] > a[i - 1])
        {
            break;
        }
    }
    if (i == a.size())
    {
        cout << ans << endl;
        return 0;
    }
    b.push_back(a[i - 1]);
    for (; i < a.size() - 1; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1] || a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            b.push_back(a[i]);
        }
    }
    b.push_back(a.back());
    if (b.size() % 2 == 0)
    {
        b.push_back(-p);
    }
    int pre = 1;
    for (int i = 1; i < b.size(); i += 2)
    {
        if (b[i] - b[pre - 1] > p && b[i] - b[i + 1] > p)
        {
            ans += p;
            pre = i + 2;
        }
        else if (b[i] - b[i + 1] > p || b[i] - b[pre - 1] < b[i] - b[i + 1])
        {
            ans += b[i] - b[pre - 1];
            pre = i + 2;
        }
        else
        {
            ans += b[i] - b[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}
