#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int m, n, ans = 0;
string word;
bool search_word(int i, int j, int di, int dj, int cnt)
{
    i += di;
    j += dj;
    if (i < 0 || i >= m || j < 0 || j >= n || a[i][j] != word[cnt])
    {
        return false;
    }
    if (cnt == word.size() - 1)
    {
        return true;
    }
    return search_word(i, j, di, dj, cnt + 1);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        cin >> word;
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == word[0])
                {
                    ans += search_word(i, j, 1, 0, 1);
                    ans += search_word(i, j, 0, 1, 1);
                    ans += search_word(i, j, 1, 1, 1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}