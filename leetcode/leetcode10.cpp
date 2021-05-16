#include<bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    regex r(p);
    return regex_match(s, r);
}
int main()
{
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p) << endl;
}