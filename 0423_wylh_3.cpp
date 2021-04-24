#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
int visit[10][10][10][10];
int n, m, px, py, bx, by, tx, ty;
int d[5] = {-1, 0, 1, 0, -1};
int bfs()
{
    visit[px][py][bx][by] = 1;
    queue<vector<int>> q;
    q.push(vector<int>{px, py, bx, by});
    while (q.size())
    {
        vector<int> t = q.front();
        q.pop();
        if (t[2] == tx && t[3] == ty)
        {
            return visit[t[0]][t[1]][t[2]][t[3]] - 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = t[0] + d[i], dy = t[1] + d[i + 1];
            if (dx < 0 || dy < 0 || dx >= n || dy >= m || grid[dx][dy] == '#')
            {
                continue;
            }
            if (dx == t[2] && dy == t[3])
            {
                if (dx + d[i] < 0 || dy + d[i + 1] < 0 || dx + d[i] >= n || dy + d[i + 1] >= m || visit[dx][dy][dx + d[i]][dy + d[i + 1]] || grid[dx + d[i]][dy + d[i + 1]] == '#')
                {
                    continue;
                }
                else
                {
                    visit[dx][dy][dx + d[i]][dy + d[i + 1]] = visit[t[0]][t[1]][t[2]][t[3]] + 1;
                    q.push(vector<int>{dx, dy, dx + d[i], dy + d[i + 1]});
                }
            }
            else
            {
                if (visit[dx][dy][t[2]][t[3]])
                {
                    continue;
                }
                visit[dx][dy][t[2]][t[3]] = visit[t[0]][t[1]][t[2]][t[3]] + 1;
                q.push(vector<int>{dx, dy, t[2], t[3]});
            }
            
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'X')
            {
                px = i, py = j;
            }
            else if (grid[i][j] == '*')
            {
                bx = i, by = j;
            }
            else if (grid[i][j] == '@')
            {
                tx = i, ty = j;
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}