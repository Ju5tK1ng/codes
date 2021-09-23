#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, m, t;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
        if (i != 0)
        {
            a[i] += a[i - 1];
        }
    }
    while(m--)
    {
        cin >> t;
        auto ite = upper_bound(a.begin(), a.end(), t);
        cout << ite - a.begin() << endl;
    }
    return 0;
}
