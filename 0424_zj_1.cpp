#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int pre = 0, cur = 1;
        string s, ans;
        cin >> s;
        ans += s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ans.back() && cur < 2 && (pre < 2 || pre == 2 && cur < 1))
            {
                ans += s[i];
                cur++;
            }
            else if (s[i] != ans.back())
            {
                ans += s[i];
                pre = cur;
                cur = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}