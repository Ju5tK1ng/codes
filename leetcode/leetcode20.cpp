#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    stack<char> sc;
    for (char& c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            sc.push(c);
        }
        else
        {
            if (!sc.empty() && (
                sc.top() == '(' && c == ')' ||
                sc.top() == '[' && c == ']' ||
                sc.top() == '{' && c == '}'))
            {
                sc.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return sc.empty();
}
int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}