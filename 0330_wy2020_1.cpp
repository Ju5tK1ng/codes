#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, t, cnt;
        cin >> n;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            cnt = 0;
            while(t)
            {
                cnt += t % 2;
                t /= 2;
            }
            cout << cnt;
            s.insert(cnt);
        }
        cout << s.size() << endl;
    }
    return 0;
}