#include <bits/stdc++.h>
using namespace std;
int b, h, n, ii, x, y, maxh;
vector<vector<int>> v;
int main()
{
    v.push_back({0, 0, 0});
    cin >> b >> h >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        maxh = max(maxh, y);
        v.push_back({x, y, x + v[i][2]});
    }
    cin >> ii >> x >> y;
    if (y < 0)
    {
        y = 0;
    }
    else if (y + maxh > h)
    {
        y = h - maxh;
    }
    if (x - v[ii - 1][2] < 0)
    {
        x = v[ii - 1][2];
    }
    else if (x + (v[n][2] - v[ii - 1][2]) > b)
    {
        x = b - (v[n][2] - v[ii - 1][2]);
    }
    x -= v[ii - 1][2];
    for (int i = 1; i <= n; i++)
    {
        cout << x + v[i - 1][2] << " " << y << endl;
    }
    return 0;
}
