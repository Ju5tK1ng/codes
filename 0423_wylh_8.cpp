#include<bits/stdc++.h>
using namespace std;
int tri[810][3];
bool visited[810];
int n, m, cnt = 0;
void sort_tri(int i)
{
    int minI = 0;
    if (tri[i][1] < tri[i][minI])
    {
        minI = 1;
    }
    if (tri[i][2] < tri[i][minI])
    {
        minI = 2;
    }
    int t0 = tri[i][minI];
    int t1 = tri[i][(minI + 1) % 3];
    int t2 = tri[i][(minI + 2) % 3];
    tri[i][0] = t0;
    tri[i][1] = t1;
    tri[i][2] = t2;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tri[i][0] >> tri[i][1] >> tri[i][2];
    }
    set<pair<int, int>> s;
    s.insert(make_pair(tri[0][0], tri[0][1]));
    s.insert(make_pair(tri[0][1], tri[0][2]));
    s.insert(make_pair(tri[0][2], tri[0][0]));
    cnt++;
    visited[0] = true;
    while (cnt != m)
    {
        for (int i = 1; i < m; i++)
        {
            if (visited[i])
            {
                continue;
            }
            for (int j = 0; j < 3; j++)
            {
                if (s.count(make_pair(tri[i][j], tri[i][(j + 1) % 3])) || s.count(make_pair(tri[i][(j + 1) % 3], tri[i][j])))
                {
                    if (s.count(make_pair(tri[i][j], tri[i][(j + 1) % 3])))
                    {
                        swap(tri[i][j], tri[i][(j + 1) % 3]);
                    }
                    s.insert(make_pair(tri[i][(j + 1) % 3], tri[i][(j + 2) % 3]));
                    s.insert(make_pair(tri[i][(j + 2) % 3], tri[i][j]));
                    cnt++;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        sort_tri(i);
        cout << tri[i][0] << " " << tri[i][1] << " " << tri[i][2] << endl;
    }
    return 0;
}