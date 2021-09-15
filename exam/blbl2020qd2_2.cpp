#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, m, d;
    char c;
    string s;
    getline(cin, s);
    istringstream ss(s);
    ss >> y >> c >> m >> c >> d;
    int m2d[12] = {31, 28, 31,   30, 31, 30,   31, 31, 30,   31, 30, 31};
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {
        m2d[1]++;
    }
    for (int i = 0; i < m - 1; i++)
    {
        d += m2d[i];
    }
    cout << d << endl;
    return 0;
}
