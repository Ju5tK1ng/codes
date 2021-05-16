#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        stack<int> s;
        set<int> out;
        int n, t;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            s.push(t);
        }
        if (!s.empty())
        {
            cout << s.top();
            out.insert(s.top());
            s.pop();
        }
        while(!s.empty())
        {
            if (!out.count(s.top()))
            {
                cout << " " << s.top();
                out.insert(s.top());
            }
            s.pop();
        }
        cout << endl;
    }
    return 0;
}