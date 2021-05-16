#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
    istringstream ss("+" + s);
    int ans = 0, pre, t;
    char preop, op;
    ss >> preop >> pre;
    while(ss >> op >> t)
    {
        if (op == '*')
        {
            pre *= t;
        }
        else if (op == '/')
        {
            pre /= t;
        }
        else
        {
            if (preop == '+')
            {
                ans += pre;
            }
            else
            {
                ans -= pre;
            }
            preop = op;
            pre = t;
        }
    }
    if (preop == '+')
    {
        ans += pre;
    }
    else
    {
        ans -= pre;
    }
    return ans;
}
// 1.1
// int calculate(string s) {
//     istringstream ss("+" + s);
//     int ans = 0, pre = 0, t;
//     char op;
//     while(ss >> op >> t)
//     {
//         if (op == '*')
//         {
//             pre *= t;
//         }
//         else if (op == '/')
//         {
//             pre /= t;
//         }
//         else if (op == '+')
//         {
//             ans += pre;
//             pre = t;
//         }
//         else
//         {
//             ans += pre;
//             pre = -t;
//         }
//     }
//     ans += pre;
//     return ans;
// }
int main()
{
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}