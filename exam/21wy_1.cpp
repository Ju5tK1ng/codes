#include <bits/stdc++.h>
using namespace std;
string i2s[10] = {"0", "1", "10", "11", "100", "101", "110", "111", "1000", "1001"};
int main()
{
    int T, n;
    char c[5];
    cin >> T;
    while (T--)
    {
        cin >> n;
        string s = "";
        while (n > 0)
        {
            int t = n % 10;
            n /= 10;
            s = i2s[t] + s;
        }
        while (s.size() > 1 && s.back() == '0')
        {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += s[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
