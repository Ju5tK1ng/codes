#include <bits/stdc++.h>
using namespace std;
long long q[30], n, ans = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = ans * 2 + q[i];
        long long t = ans;
        string s = "";
        if (t == 0)
        {
            s = "0";
        }
        while (t)
        {
            s = to_string(t % 8) + s;
            t /= 8;
        }
        cout << s << endl;
    }
    return 0;
}
