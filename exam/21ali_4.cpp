#include <bits/stdc++.h>
using namespace std;
string a, b;
int q;

string upper(string s)
{
    for (char& c : s)
    {
        if (c >= 'a')
        {
            c += 32;
        }
    }
    return s;
}

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        int i = 0, j = 0;
        string t;
        while(i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                t = "";
                i++;
                j++;
            }
            else if (a[i] - 32 == b[j])
            {
                t = "";
                while(i < a.size() && j < b.size() && a[i] >= 'a' && b[i] <= 'Z')
                {
                    if (a[i] - 32 == b[j])
                    {
                        t += b[j];
                        i++;
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                if (a[i] == t[0] && i + t.size() - 1 < a.size() && upper(a.substr(i, t.size())) == t)
                {
                    i += t.size();
                }
                else if (a[i] >= 'a')
                {
                    i++;
                }
                else
                {
                    break;
                }
                t = "";
            }
        }
        while (i < a.size())
        {
            if (a[i] == t[0] && i + t.size() - 1 < a.size() && upper(a.substr(i, t.size())) == t)
            {
                i += t.size();
            }
            else if (a[i] >= 'a')
            {
                i++;
            }
            else
            {
                break;
            }
            t = "";
        }
        if (i == a.size() && j == b.size())
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
