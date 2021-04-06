#include<bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int>& arr) {
    int ans = 0, maxn = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxn = max(maxn, arr[i]);
        if (maxn == i)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxChunksToSorted(arr) << endl;
    return 0;
}