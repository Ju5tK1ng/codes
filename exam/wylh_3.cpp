#include<bits/stdc++.h>
using namespace std;
int R, C, Y, X;
int SY, SX;
int ans = -1;
char m[11][11];
bool visit[11][11];
int d[5] = {-1, 0, 1, 0, -1};
unordered_map<int, int> um;
int box = -1;
void dfs(int y, int x, int cnt, int choose, int path)
{
    if (y < 0 || y >= R || x < 0 || x >= C || m[y][x] == '#' || cnt > Y - X || visit[y][x])
    {
        return;
    }
    if (m[y][x] >= 'a' && m[y][x] <= 'a' + box)
    {
        cnt++;
        choose |= 1 << (m[y][x] - 'a');
    }
    else if (m[y][x] == 'T')
    {
        for (auto& t : um)
        {
            if ((t.first & choose) == 0)
            {
                t.second = min(t.second, path);
            }
        }
        return;
    }
    visit[y][x] = true;
    for (int k = 0; k < 4; k++)
    {
        int dy = y + d[k];
        int dx = x + d[k + 1];
        dfs(dy, dx, cnt, choose, path + 1);
    }
    visit[y][x] = false;
}
int cal(int i)
{
    int ans = 0;
    while(i)
    {
        ans += i & 1;
        i = i >> 1;
    }
    return ans;
}
int main()
{
    cin >> R >> C >> Y >> X;
    for (int i = 0; i < (1 << Y); i++)
    {
        if (cal(i) == X)
        {
            um[i] = INT_MAX;
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 'S')
            {
                SY = i;
                SX = j;
            }
            else if (m[i][j] == '?')
            {
                box++;
                m[i][j] = 'a' + box;
            }
        }
    }
    dfs(SY, SX, 0, 0, 1);
    for (auto& t : um)
    {
        if (t.second != INT_MAX)
        {
            ans = max(ans, t.second);
        }
    }
    cout << ans << endl;
    return 0;
}
