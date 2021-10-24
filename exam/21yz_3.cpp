#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool a[100000000] = {false};
    int n;
    a[1] = true;
    cin >> n;
    for (int i = 1; i < 100000000; i++)
    {
        if (a[i])
        {
            a[i * 2] = true;
            a[i * 3] = true;
            a[i * 7] = true;
            n--;
        }
        if (n == -2)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

int main()
{
    unordered_set<int> a;
    a.insert(1);
    int n;
    cin >> n;
    for (int i = 1; i < 100000000; i++)
    {
        if (a.count(i))
        {
            a.insert(i * 2);
            a.insert(i * 3);
            a.insert(i * 7);
            n--;
        }
        if (n == -2)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
