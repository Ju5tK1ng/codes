#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> name, nums, act;
    string s, t;
    getline(cin, s);
    istringstream ss1(s);
    while (ss1 >> t)
    {
        name.push_back(t);
    }
    getline(cin, s);
    getline(cin, s);
    istringstream ss2(s);
    while (ss1 >> t)
    {
        act.push_back(t);
    }
    int n = name.size();
    unordered_map<string, vector<string>> m1;
    for (int i = 0; i < n; i++)
    {
        m1[name[i]].push_back(act[i]);
    }
    map<string, int> m2;
    for (auto& p : m1)
    {
        int s = p.second.size();
        for (int i = 0; i < s - 2; i++)
        {
            for (int j = i + 1; j < s - 1; j++)
            {
                for (int k = j + 1; k < s; k++)
                {
                    m2[p.second[i] + p.second[j] + p.second[k]]++;
                }
            }
        }
    }
    int maxn = 0;
    string ans;
    for (auto& p : m2)
    {
        if (p.second > maxn)
        {
            maxn = p.second;
            ans = p.first;
        }
    }
    cout << ans << endl;
    return 0;
}