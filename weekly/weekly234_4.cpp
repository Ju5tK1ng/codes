#include<bits/stdc++.h>
using namespace std; 
int maxNiceDivisors(int primeFactors) {
    const int mod = 1e9 + 7;
    int a = round(sqrt(primeFactors));
    int b = primeFactors / a;
    int ans = 1;
    primeFactors -= a * b;
    for (int i = 0; i < a; i++)
    {
        if (i < primeFactors)
        {
            // cout << b + 1 << endl;
            ans = (ans % mod) * (b + 1);
        }
        else
        {
            // cout << b << endl;
            ans = (ans % mod) * b;
        }
    }
    return ans % mod;
}