#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum;
    vector<int> v;
    unordered_set<int> us;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sum;
        v.push_back(sum);
    }
    cin >> sum;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (us.count(sum - v[i]))
        {
            cout << sum - v[i] << " " << v[i] << endl;
            found = true;
            break;
        }
        us.insert(v[i]);
    }
    if (!found)
    {
        cout << "notfound" << endl;
    }
    return 0;
}
