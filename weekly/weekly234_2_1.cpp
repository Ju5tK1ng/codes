#include<bits/stdc++.h>
using namespace std;
int reinitializePermutation(int n) {
    vector<int> start(n);
    vector<int> perm(n);
    vector<int> arr(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        start[i] = i;
        perm[i] = i;
    }
    while (start != arr)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = perm[i / 2];
            }
            else
            {
                arr[i] = perm[n / 2 + (i - 1) / 2];
            }
        }
        perm = arr;
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << reinitializePermutation(n) << endl;
    return 0;
}