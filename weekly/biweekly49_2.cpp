#include<bits/stdc++.h>
using namespace std;
// 1.1
bool areSentencesSimilar(string sentence1, string sentence2) {
    istringstream ss1(sentence1);
    istringstream ss2(sentence2);
    string s;
    vector<string> vs1, vs2;
    while (ss1 >> s)
    {
        vs1.push_back(s);
    }
    while (ss2 >> s)
    {
        vs2.push_back(s);
    }
    if (vs1.size() > vs2.size())
    {
        vs1.swap(vs2);
    }
    int cnt1 = 0, cnt2 = 0;
    while (cnt1 < vs1.size() && vs1[cnt1] == vs2[cnt1])
    {
        cnt1++;
    }
    while (cnt2 < vs1.size() && vs1[vs1.size() - 1 - cnt2] == vs2[vs2.size() - 1 - cnt2])
    {
        cnt2++;
    }
    return cnt1 + cnt2 >= vs1.size();
}