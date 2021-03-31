#include<bits/stdc++.h>
using namespace std;
int m[10010][10010], p[10010];
int anum, bnum, n, t, cnt;
bool visit[10010];
bool match(int i)
{
	for (int j = 0; j < bnum; j++)
	{
		if (m[i][j] && !visit[j])
		{
			visit[j] = true;
			if (p[j] == 0 || match(p[j]))
			{
				p[j] = i;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	map<int, int> mapa, mapb;
    string s;
    getline(cin, s);
    istringstream ss1(s);
    while (ss1 >> t)
    {
        mapa[t] = anum++;
    }
    getline(cin, s);
    istringstream ss2(s);
    while (ss2 >> t)
    {
        mapb[t] = bnum++;
    }
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		m[mapa[t1]][mapb[t2]] = 1;
	}
	for (int i = 0; i < anum; i++)
	{
		memset (visit, 0, sizeof(visit));
		if (match(i))
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}