#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    string s;
    unordered_map<string, int> um;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        um[s]++;
    }
    for (auto& p : um)
    {
        if (p.second * 100 >= n)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
