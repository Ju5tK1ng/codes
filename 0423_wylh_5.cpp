#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int a[1010][4];
int n, m, x, y;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        a[i][2] += a[i][0];
        a[i][3] += a[i][1];
        s.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        bool find = false;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (a[s[j]][0] <= x && a[s[j]][1] <= y && a[s[j]][2] >= x && a[s[j]][3] >= y)
            {
                cout << s[j] << endl;
                s.push_back(s[j]);
                s.erase(s.begin() + j);
                find = true;
                break;
            }
        }
        if (!find)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}