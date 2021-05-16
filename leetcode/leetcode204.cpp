#include<bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
    if (n <= 2)
    {
        return 0;
    }
    int count = n - 2;
    bool prime[n];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i <= n / 2; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j < n; j += i)
            {
                if (prime[j])
                {
                    prime[j] = false;
                    count--;
                }
            }
        }
    }
    return count;
}
// 1.1
// int countPrimes(int n) {
//     if (n <= 2)
//     {
//         return 0;
//     }
//     int sqrtn = sqrt(n), count = n / 2;
//     bool prime[n];
//     memset(prime, true, sizeof(prime));
//     for (int i = 3; i <= sqrtn; i += 2)
//     {
//         if (prime[i])
//         {
//             for (int j = i * i; j < n; j += 2 * i)
//             {
//                 if (prime[j])
//                 {
//                     prime[j] = false;
//                     count--;
//                 }
//             }
//         }
//     }
//     return count;
// }
int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;
    return 0;
}