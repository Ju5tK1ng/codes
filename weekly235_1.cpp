#include<bits/stdc++.h>
using namespace std; 
string truncateSentence(string s, int k) {
    istringstream ss(s);
    string ans;
    string t;
    k--;
    ss >> ans;
    while (k--)
    {
        ss >> t;
        ans = ans + ' ' + t;
    }
    return ans;
}