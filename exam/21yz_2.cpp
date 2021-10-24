#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    int t, sum = 0, ans = 0;
    while (cin >> t)
    {
        a.push_back(t);
        sum += t;
    }
    t = sum / a.size();
    sum = 0;
    for (int& i : a)
    {
        sum += t - i;
        if (sum != 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
