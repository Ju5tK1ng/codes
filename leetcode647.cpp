#include<bits/stdc++.h>
using namespace std;
int countSub(string s, int i, int j)
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
int countSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans += countSub(s, i, i);
        ans += countSub(s, i, i + 1);
    }
    return ans;
}
// 1.1
// int countSubstrings(string s) {
//     int ans = 0, l, r;
//     for (int i = 0; i < s.size(); i++)
//     {
//         l = i;
//         r = i;
//         while (l >= 0 && r < s.size() && s[l] == s[r])
//         {
//             ans++;
//             l--;
//             r++;
//         }
//         l = i;
//         r = i + 1;
//         while (l >= 0 && r < s.size() && s[l] == s[r])
//         {
//             ans++;
//             l--;
//             r++;
//         }
//     }
//     return ans;
// }
int main()
{
    string s;
    cin >> s;
    cout << countSubstrings(s) << endl;
    return 0;
}