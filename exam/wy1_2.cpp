#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int ans = 0, cnt = 0;
        string s;
        cin >> s;
        while(cnt < s.size())
        {
            ans += 3;
            if (s[cnt] == '%')
            {
                cnt++;
                label:
                if (cnt == s.size())
                {
                    break;
                }
                if (s[cnt] == 's')
                {
                    ans += 3;
                }
                else if (s[cnt] == 'd')
                {
                    ans += 4;
                }
                else if (s[cnt] == 'u')
                {
                    ans += 5;
                }
                else if (s[cnt] == 'p')
                {
                    ans += 6;
                }
                else if (s[cnt] == 'f')
                {
                    ans += 7;
                }
                else if (s[cnt] >= '0' && s[cnt] <= '9')
                {
                    ans += 8;
                    cnt++;
                    if (cnt == s.size())
                    {
                        break;
                    }
                    while (s[cnt] >= '0' && s[cnt] <= '9')
                    {
                        ans += 8;
                        cnt++;
                    }
                    goto label;
                }
                else
                {
                    ans += 9;
                }
            }
            cnt++;
        }
        ans++;
        cout << ans << endl;
    }
    return 0;
}