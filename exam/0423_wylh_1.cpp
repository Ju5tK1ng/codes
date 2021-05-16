#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    char letter = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == letter)
        {
            cnt++;
        }
        else
        {
            cout << cnt << letter;
            letter = s[i];
            cnt = 1;
        }
    }
    cout << cnt << letter << endl;
    return 0;
}