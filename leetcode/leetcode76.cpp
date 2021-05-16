#include<bits/stdc++.h>
using namespace std;
// 1.1
string minWindow(string s, string t) {
    int chars[128];
    memset(chars, 0, sizeof(chars));
    int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
    for(auto c:t)
    {
        chars[c]++;
    }
    for(int r = 0; r < s.size(); r++)
    {
        if (--chars[s[r]] >= 0)
        {
            cnt++;
        }
        while (cnt == t.size())
        {
            if (r - l + 1 < min_size)
            {
                min_l = l;
                min_size = r - l + 1;
            }
            if (++chars[s[l]] > 0)
            {
                cnt--;
            }
            l++;
        }
    }
    if (min_size > s.size())
    {
        return "";
    }
    else
    {
        return s.substr(min_l, min_size);
    }
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}