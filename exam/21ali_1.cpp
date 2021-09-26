#include <bits/stdc++.h>
using namespace std;
int a[55], n, x, y;
int main()
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for (int i = 4; i <= 50; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        cout << a[y - x] << endl;
    }
    return 0;
}