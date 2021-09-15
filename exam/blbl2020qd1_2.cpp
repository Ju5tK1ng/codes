#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (st.empty() || c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (!st.empty() && (st.top() == '(' && c == ')' || st.top() == '[' && c == ']' || st.top() == '{' && c == '}'))
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
    }
    if (st.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
