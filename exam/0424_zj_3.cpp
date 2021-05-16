#include<bits/stdc++.h>
using namespace std;
bool judge(vector<int> v)
{
    for (int i = 1; i <= 9; i++)
    {
        if (v[i] < 0)
        {
            return false;
        }
        if (v[i] >= 3)
        {
            v[i] -= 3;
        }
        if (v[i] > 0 && i > 7)
        {
            return false;
        }
        if (v[i] > 0 && i <= 7)
        {
            v[i + 1] -= v[i];
            v[i + 2] -= v[i];
            v[i] = 0;
        }
    }
    return true;
}
int main()
{
    vector<int> v(10, 0), ans;
    int t;
    for (int i = 0; i < 13; i++)
    {
        cin >> t;
        v[t]++;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (v[i] < 4)
        {
            v[i]++;
            for (int j = 1; j <= 9; j++)
            {
                if (v[j] >= 2)
                {
                    v[j] -= 2;
                    if (judge(v))
                    {
                        ans.push_back(i);
                    }
                    v[j] += 2;
                }
            }
            v[i]--;
        }
    }
    if (ans.size() > 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            i != ans.size() - 1 ? cout << ans[i] << " " : cout << ans[i] << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}