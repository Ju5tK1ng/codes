#include<bits/stdc++.h>
using namespace std;
int m, n, x, y, r;
int k;
int player[210][3];
int c;
int d, t;
vector<int> ans(1, 0);
char cha;
bool cmp(vector<int>& x, vector<int>& y)
{
    return x[1] < y[1];
}
int main()
{
    cin >> m >> n >> x >> y >> r;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> player[i][0] >> player[i][1];
        if (abs(player[i][0] - x) <= r && abs(player[i][1] - y) <= r)
        {
            player[i][2] = 1;
            ans[0]++;
        }
    }
    cin >> c;
    vector<vector<int>> act(c, vector<int>(5, 0));
    for (int i = 0; i < c; i++)
    {
        cin >> act[i][0] >> act[i][1] >> act[i][2];
        cin >> cha;
        if (cha == 'W')
        {
            act[i][4] = 1 * act[i][2];
        }
        else if (cha == 'A')
        {
            act[i][3] = -1 * act[i][2];
        }
        else if (cha == 'S')
        {
            act[i][4] = -1 * act[i][2];
        }
        else
        {
            act[i][3] = 1 * act[i][2];
        }  
    }
    sort(act.begin(), act.end(), cmp);
    for (int i = 0; i < c; i++)
    {
        int p = act[i][0];
        while (ans.size() - 1 < act[i][1])
        {
            ans.push_back(ans.back());
        }
        player[p][0] += act[i][3];
        if (player[p][0] < 1) player[p][0] = 1;
        if (player[p][0] > m) player[p][0] = m;
        player[p][1] += act[i][4];
        if (player[p][1] < 1) player[p][1] = 1;
        if (player[p][1] > n) player[p][1] = n;
        if (abs(player[p][0] - x) <= r && abs(player[p][1] - y) <= r)
        {
            if (player[p][2] == 0)
            {
                ans.back()++;
            }
            player[p][2] = 1;
        }
        else
        {
            if (player[p][2] == 1)
            {
                ans.back()--;
            }
            player[p][2] = 0;
        }
    }
    cin >> d;
    while (d--)
    {
        cin >> t;
        if (t > ans.size() - 1)
        {
            d != 0 ? cout << ans.back() << " " : cout << ans.back() << endl;
        }
        else
        {
            d != 0 ? cout << ans[t] << " " : cout << ans[t] << endl;
        }
    }
    return 0;
}
