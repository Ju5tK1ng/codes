#include<bits/stdc++.h>
using namespace std;
struct Comp
{
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
int a[1000010];
int main()
{
    std::ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push(make_pair(a[i], i));
    }
    for (int i = 0; i < k; i++)
    {
        auto p = q.top();
        q.pop();
        cout << p.second << endl;
        p.first += a[p.second];
        q.push(p);
    }
    return 0;
}