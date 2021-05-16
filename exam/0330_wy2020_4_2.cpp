// 2.0
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int ans = 1, prepre = 0, pre = 0, cur = 0;
        for (int i = 1; i <= len; i++)
        {
            if (s[i - 1] == 'N')
            {
                cur++;
                pre++;
                prepre++;
            }
            else
            {
                cur = pre + 1;
                pre = prepre + 1;
                prepre = 0;
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}