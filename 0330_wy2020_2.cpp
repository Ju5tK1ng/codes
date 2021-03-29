#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    bool sunk[n + 2];
    memset(sunk, 0, sizeof(sunk));
    sunk[0] = sunk[n + 1] = true;
    cin >> q;
    vector<pair<int, int>> b(q);
    for (int i = 0; i < q; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0, curans = 1, ans[q];
    for (int i = 0; i < q; i++)
    {
        while(cnt < n && b[i].first >= a[cnt].first)
        {
            int index = a[cnt].second;
            sunk[index] = true;
            if (sunk[index - 1] && sunk[index + 1])
            {
                curans --;
            }
            else if (!sunk[index - 1] && !sunk[index + 1])
            {
                curans ++;
            }
            cnt++;
        }
        ans[b[i].second] = curans;
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}