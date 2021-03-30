#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string time;
        cin >> time;
        istringstream ss(time);
        int h, m, s;
        char c;
        ss >> h >> c >> m >> c >> s;
        if (h > 23)
        {
            h %= 10;
        }
        if (m > 59)
        {
            m %= 10;
        }
        if (s > 59)
        {
            s %= 10;
        }
        printf("%02d:%02d:%02d\n", h, m, s);
    }
    return 0;
}