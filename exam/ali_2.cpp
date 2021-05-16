#include<bits/stdc++.h>
using namespace std;
long long n, maxn = 7e7;
int main()
{
    cin >> n;
    vector<long long> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        // maxn = max(maxn, num[i]);
    }
    vector<bool> prime(maxn + 1, true);
    for (int i = 2; i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j <= maxn; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (num[i] == 1)
        {
            cout << 0 << endl;
        }
        else if (num[i] <= maxn && prime[num[i]])
        {
            cout << num[i] << endl;
        }
        else
        {
            for (int j = min(maxn, num[i] / 2); j >= 2; j--)
            {
                if (prime[j] && num[i] % j == 0)
                {
                    cout << j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}