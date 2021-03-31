#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
    int a[128], b[128];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i]] != b[t[i]])
        {
            return false;
        }
        a[s[i]] = b[t[i]] = i + 1;
    }
    return true;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << isIsomorphic(s, t) << endl;
    return 0;
}