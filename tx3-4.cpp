#include<bits/stdc++.h>
using namespace std;
bool judge(string a, string b)
{
    int n = a.size();
    if (n % 2)
    {
        return a == b;
    }
    else
    {
        return judge(a.substr(0, n / 2), b.substr(0, n / 2)) && judge(a.substr(n / 2, n), b.substr(n / 2, n)) || judge(a.substr(0, n / 2), b.substr(n / 2, n)) && judge(a.substr(n / 2, n), b.substr(0, n / 2));
    }
}
int main()
{
    int t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        if (judge(a, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}