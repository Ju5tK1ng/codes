#include <bits/stdc++.h>
using namespace std;
vector<int> a(10000);

void primes(int n) {
    int sqrtn = sqrt(n);
    bool prime[n];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i <= sqrtn; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j < n; j += i)
            {
                if (prime[j])
                {
                    prime[j] = false;
                }
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            a.push_back(i);
        }
    }
    return;
}

int main()
{
    primes(21000);
    int T, x;
    cin >> T;
    while (T--)
    {
        cin >> x;
        auto ite1 = lower_bound(a.begin(), a.end(), 1 + x);
        auto ite2 = lower_bound(a.begin(), a.end(), *ite1 + x);
        cout << *ite1 * *ite2 << endl;
    }
    return 0;
}
