#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    if (n < 4)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<string> str(n);
    string ansstr;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            str[i] = '1';
        }
        for (int j = 0; j < i; j++)
        {
            if (s[j] == '1' && (s[i] == '1' || s[i] == '8') || s[j] == '8' && (s[i] == '8' || s[i] == '0') || s[j] == '0' && (s[i] == '0' || s[i] == '7') || s[j] == '7' && s[i] == '7')
            {
                if (str[j].size() >= str[i].size())
                {
                    str[i] = str[j] + s[i];
                }
            }
        }
        if (str[i].size() > ansstr.size())
        {
            ansstr = str[i];
        }
    }
    bool ok[4];
    memset(ok, false, sizeof(ok));
    for (char c : ansstr)
    {
        if (c == '1')
        {
            ok[0] = true;
        }
        else if (c == '8')
        {
            ok[1] = true;
        }
        else if (c == '0')
        {
            ok[2] = true;
        }
        else if (c == '7')
        {
            ok[3] = true;
        }
    }
    if (ok[0] && ok[1] && ok[2] && ok[3])
    {
        cout << ansstr << endl;
        cout << ansstr.size() << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}