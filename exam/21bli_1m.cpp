#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void func(int a, int n)
{
    int i = n, j;
    for (int i = a; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            func(i, n / i);
        }
    }
}

int main()
{
    int t, a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        cnt = 1;
        func(2, a);
        cout << cnt << endl;
    }
    return 0;
}
