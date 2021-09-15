#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    vector<int> v;
    int k, end;
    while (cin >> s)
    {
        if (s == "#")
        {
            break;
        }
        v.push_back(atoi(s.c_str()));
    }
    cin >> k;
    for (int i = 0; i < v.size(); i++)
    {
        if (i % k == 0)
        {
            end = i + k - 1;
        }
        if (end >= v.size())
        {
            if (i != v.size() - 1)
            {
                cout << v[i] << "->";
            }
            else
            {
                cout << v[i] << endl;
            }
        }
        else
        {
            if (i != v.size() - 1)
            {
                cout << v[end - (i % k)] << "->";
            }
            else
            {
                cout << v[end - (i % k)] << endl;
            }
        }
    }
    return 0;
}
