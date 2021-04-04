#include<bits/stdc++.h>
using namespace std;
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
    bool ok1 = false, ok2 = false;
    while (cnt1 < vs1.size() && cnt2 < vs2.size() && vs1[cnt1] == vs2[cnt2])
    {
        ok1 = true;
        cnt1++;
        cnt2++;
    }
    while (cnt2 < vs2.size() && vs1[cnt1] != vs2[cnt2])
    {
        cnt2++;
    }
    while (cnt1 < vs1.size() && cnt2 < vs2.size() && vs1[cnt1] == vs2[cnt2])
    {
        ok2 = true;
        cnt1++;
        cnt2++;
    }
    if (cnt1 == vs1.size() && ok1 && ok2)
    {
        return true;
    }
    return false;
}