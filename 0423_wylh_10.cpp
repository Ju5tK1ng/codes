#include<bits/stdc++.h>
using namespace std;
int prime[30], n, cnt;
bool is_prime[30];
int main()
{
    cin >> n;
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < 30; i++)
    {
        if (is_prime[i])
        {
            prime[cnt++] = i;
            for (int j = i * 2; j < 30; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    double up = 1, down = 1;
    for (int i = 0; down * prime[i] <= n; i++)
    {
        down *= prime[i];
        up *= prime[i] - 1;   
    }
    printf("%.6lf\n", up / down);
    return 0;
}