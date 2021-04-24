#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p, q;
    cin >> p >> q;
    if (p == 1 && q == 1)
    {
        cout << 1 << " " << 1 << endl; 
        return 0;
    }
    list<pair<int, int>> l;
    l.push_back(make_pair(0, 1));
    l.push_back(make_pair(1, 1));
    l.push_back(make_pair(1, 0));
    for (int i = 2; i <= 12; i++)
    {
        auto jpre = l.begin();
        auto j = l.begin();
        int cnt = 0;
        j++;
        while (j != l.end())
        {
            int x = jpre->first + j->first;
            int y = jpre->second + j->second;
            cnt++;
            if (x == p && y == q)
            {
                cout << i << " " << cnt << endl;
                return 0;
            }
            l.insert(j, make_pair(x, y));
            jpre++;
            jpre++;
            j++;
        }
    }
    return 0;
}