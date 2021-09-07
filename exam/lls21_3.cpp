#include <bits/stdc++.h>
using namespace std;

map<int, short> t2order;
vector<queue<pair<string, list<pair<short, string>>::iterator>>> v(105);
list<pair<short, string>> l;

int main()
{
    int n, t;
    cin >> n;
    string cmd;
    short order = 0;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "in")
        {
            cin >> t;
            cin >> cmd;
            if (!t2order.count(t))
            {
                t2order[t] = order++;
            }
            short o = t2order[t];
            l.push_front(make_pair(o, cmd));
            v[o].push(make_pair(cmd, l.begin()));
        }
        else
        {
            cin >> t;
            if (l.empty() || t != 0 && (!t2order.count(t) || v[t2order[t]].empty()))
            {
                cout << -1 << endl;
            }
            else
            {
                if (t == 0)
                {
                    short o = l.back().first;
                    l.pop_back();
                    cout << v[o].front().first << endl;
                    v[o].pop();
                }
                else
                {
                    short o = t2order[t];
                    l.erase(v[o].front().second);
                    cout << v[o].front().first << endl;
                    v[o].pop();
                }
            }
        }
    }
    return 0;
}
