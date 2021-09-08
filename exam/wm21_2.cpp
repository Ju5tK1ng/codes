#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> dic;
int cnt = 1;
string str;
int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        string s = "";
        if (!dic.count(s + str[i]))
        {
            dic[s + str[i]] = cnt++;
            cout << 0 << str[i];
        }
        else
        {
            while (i < str.size() && dic.count(s + str[i]))
            {
                s += str[i];
                i++;
            }
            if (i == str.size())
            {
                cout << dic[s];
            }
            else
            {
                dic[s + str[i]] = cnt++;
                cout << dic[s] << str[i];
            }
        }
    }
    cout << endl;
    return 0;
}
