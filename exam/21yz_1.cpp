#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[5], sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum = sum == 0 ? 1 : sum;
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            cout << a[i] * 100 / sum << endl;
        }
        else
        {
            cout << a[i] * 100 / sum << " ";
        }
    }
    return 0;
}
