#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, pre2 = 1, pre1 = 2, cur;
    cin >> n;
    if (n <= 2)
    {
        cout << n << endl;
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        cur = pre1 + pre2;
        pre2 = pre1;
        pre1 = cur;
    }
    cout << cur << endl;
    return 0;
}
