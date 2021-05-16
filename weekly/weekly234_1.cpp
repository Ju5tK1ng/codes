#include<bits/stdc++.h>
using namespace std;
int numDifferentIntegers(string word) {
    unordered_set<string> s;
    string t = "";
    bool ok = false;
    for (char c : word)
    {
        if (c >= '0' && c <= '9')
        {
            if (t.size() == 1 && t[0] == '0')
            {
                t = "";
            }
            t += c;
            ok = true;
        }
        else if (ok)
        {
            s.insert(t);
            ok = false;
            t = "";
        }
    }
    if (ok)
    {
        s.insert(t);
    }
    return s.size();
}
int main()
{
    string word;
    cin >> word;
    cout << numDifferentIntegers(word) << endl;
    return 0;
}