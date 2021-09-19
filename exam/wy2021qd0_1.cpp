#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= 100000; i++)
    {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
    }
    int T, n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
