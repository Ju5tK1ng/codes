#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, unordered_set<string>> ss;
    unordered_map<string, int> ans;
    vector<string> keys;
    queue<string> q;
    int n;
    cin >> n;
    string s, key;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        istringstream iss(s);
        iss >> key;
        ans[key]++;
        keys.push_back(key);
        while (iss >> s)
        {
            ss[key].insert(s);
        }
    }
    for (auto& key : keys)
    {
        for (auto& str : ss[key])
        {
            q.push(str);
        }
        while (!q.empty())
        {
            if (ss.count(q.front()))
            {
                for (auto& str : ss[q.front()])
                {
                    if (!ss[key].count(str))
                    {
                        ss[key].insert(str);
                        q.push(str);
                    }
                }
            }
            ans[q.front()]++;
            q.pop();
        }
        // for (auto& str : ss[key])
        // {
        //     cout << str << " ";
        // }
        // cout << endl;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cout << ans[s] << endl;
    }
    return 0;
}