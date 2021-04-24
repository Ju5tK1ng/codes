#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>& x, pair<int, int>& y)
{
    if (x.first * x.second == y.first * y.second)
    {
        if (min(x.first, x.second) == min(y.first, y.second))
        {
            return x.first < y.first;
        }
        return min(x.first, x.second) > min(y.first, y.second);
    }
    return x.first * x.second < y.first * y.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        i != n - 1 ? cout << v[i].first << " " << v[i].second << " " : cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}