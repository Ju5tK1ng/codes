#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[1010];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
            sum += a[i].second;
        }
        sort(a, a + n, [](const auto& x, const auto& y)
        {
            if (x.first == y.first) return x.second > y.second;
            return x.first < y.first;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        int use = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first > use)
            {
                pq.push(a[i].second);
                sum -= a[i].second;
                use++;
            }
            else if (a[i].second > pq.top())
            {
                sum -= a[i].second - pq.top();
                pq.pop();
                pq.push(a[i].second);
            }
        }
        cout << sum << endl;
    }
    return 0;
}