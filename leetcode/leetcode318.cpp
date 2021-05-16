#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<string>& words) {
    unordered_map<int, int> m;
    int ans = 0;
    for (string& word : words)
    {
        int mask = 0, len = word.size();
        for (char& c : word)
        {
            mask |= 1 << (c - 'a');
        }
        for (auto& t : m)
        {
            if (!(t.first & mask))
            {
                ans = max(ans, t.second * len);
            }
        }
        m[mask] = max(m[mask], len);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout << maxProduct(words) << endl;
    return 0;
}