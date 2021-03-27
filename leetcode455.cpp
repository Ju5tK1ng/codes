#include<bits/stdc++.h>
using namespace std;
// 1.1
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size())
    {
        if (g[child] <= s[cookie])
        {
            child++;
        }
        cookie++;
    }
    return child;
}
int main()
{
    vector<int> g, s;
    int I, J, t;
    cin >> I >> J;
    for (int i = 0; i < I; i++)
    {
        cin >> t;
        g.push_back(t);
    }
    for (int j = 0; j < J; j++)
    {
        cin >> t;
        s.push_back(t);
    }
    cout << findContentChildren(g, s) << endl;
    return 0;
}