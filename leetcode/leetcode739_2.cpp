#include<bits/stdc++.h>
using namespace std;
// 2.0
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ans(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        int j = i + 1;
        while(true)
        {
            if (T[i] < T[j])
            {
                ans[i] = j - i;
                break;
            }
            else if (ans[j] == 0)
            {
                ans[i] == 0;
                break;
            }
            j += ans[j];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    vector<int> ans = dailyTemperatures(T);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (n != i - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    return 0;
}