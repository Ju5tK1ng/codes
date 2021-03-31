#include<bits/stdc++.h>
using namespace std;
int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, ans = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cur++;
        }
        else
        {
            pre = cur;
            cur = 1;
        }
        if (pre >= cur)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << countBinarySubstrings(s) << endl;
    return 0;
}