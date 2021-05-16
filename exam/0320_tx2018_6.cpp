#include<bits/stdc++.h>
using namespace std;
char start[55][55], endState[55][55];
int n, m, ans;
void dfsY(int i, int j, int delta)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (start[i][j] != endState[i][j])
	{
		if (start[i][j] == 'X' && endState[i][j] != 'B')
		{
			start[i][j] = 'Y';
			dfsY(i + delta, j + delta, delta);
		}
		else if (start[i][j] == 'B' && endState[i][j] == 'G')
		{
			start[i][j] = 'G';
			dfsY(i + delta, j + delta, delta);
		}
	}
}
void dfsB(int i, int j, int delta)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (start[i][j] != endState[i][j])
	{
		if (start[i][j] == 'X' && endState[i][j] != 'Y')
		{
			start[i][j] = 'B';
			dfsB(i + delta, j - delta, delta);
		}
		else if (start[i][j] == 'Y' && endState[i][j] == 'G')
		{
			start[i][j] = 'G';
			dfsB(i + delta, j - delta, delta);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			start[i][j] = 'X';
			cin >> endState[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (start[i][j] != endState[i][j])
			{
				if (start[i][j] == 'X' && endState[i][j] == 'Y')
				{
					start[i][j] = 'Y';
					dfsY(i + 1, j + 1, 1);
					dfsY(i - 1, j - 1, -1);
				}
				else if (start[i][j] == 'X' && endState[i][j] == 'B')
				{
					start[i][j] = 'B';
					dfsB(i + 1, j - 1, 1);
					dfsB(i - 1, j + 1, -1);
				}
				else if (start[i][j] == 'X' && endState[i][j] == 'G')
				{
					start[i][j] = 'G';
					dfsY(i + 1, j + 1, 1);
					dfsY(i - 1, j - 1, -1);
					dfsB(i + 1, j - 1, 1);
					dfsB(i - 1, j + 1, -1);
					ans++;
				}
				else if (start[i][j] == 'Y')
				{
					start[i][j] = 'G';
					dfsB(i + 1, j - 1, 1);
					dfsB(i - 1, j + 1, -1);
				}
				else if (start[i][j] == 'B')
				{
					start[i][j] = 'G';
					dfsY(i + 1, j + 1, 1);
					dfsY(i - 1, j - 1, -1);
				}
				ans++;
//				for (int i = 0; i < n; i++)
//				{
//					for (int j = 0; j < m; j++)
//					{
//						cout << start[i][j];
//					}
//					cout << endl;
//				}
//				cout << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
