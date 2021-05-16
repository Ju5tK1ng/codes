#include<bits/stdc++.h>
using namespace std;
int substr(string s, int i, int j)
{
    int cnt = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        cnt++;
        i--;
        j++;
    }
    return cnt;
}
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        ans += substr(s, i, i + 1);
        ans += substr(s, i - 1, i + 1);
    }
    cout << ans << endl;
}