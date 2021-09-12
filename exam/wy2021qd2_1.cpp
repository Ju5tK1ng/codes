#include <bits/stdc++.h>
using namespace std;

// // 1.0
// int main() {
//     string s,t;
//     cin >> s >> t;
//     int index = -1;
//     for(char i : s){
//         index = t.find(i,index + 1);
//         if(index >= t.size()) break;
//     }
//     string b = index < t.size() ? "true" : "false";
//     cout << b << endl;
//     return 0;
// }

// 2.0
int main()
{
    string s, l;
    cin >> s >> l;
    int i = 0, j = 0;
    while (i < s.size() && j < l.size())
    {
        if (s[i] == l[j])
        {
            i++;
        }
        j++;
    }
    // for (j = 0; i < s.size() && j < l.size(); j++)
    // {
    //     if (s[i] == l[j])
    //     {
    //         i++;
    //     }
    // }
    if (i == s.size())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
