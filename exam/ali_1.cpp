#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (char& c : s)
    {
        if (c == 'A')
        {
            cout << c;
        }
    }
    for (char& c : s)
    {
        if (c == 'B')
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}