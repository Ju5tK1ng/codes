#include<bits/stdc++.h>
using namespace std;
// 2.2
int candy(vector<int>& ratings) {
    int rsize = ratings.size();
    int cnt[rsize];
    cnt[0] = 1;
    for (int i = 1; i < rsize; i++)
    {
        cnt[i] = 1;
        if (ratings[i - 1] < ratings[i])
        {
            cnt[i] = cnt[i - 1] + 1;
        }
    }
    int ans = cnt[rsize - 1];
    for (int i = rsize - 1; i > 0; i--)
    {
        if(ratings[i - 1] > ratings[i])
        {
            cnt[i - 1] = max(cnt[i - 1], cnt[i] + 1);
        }
        ans += cnt[i - 1];
    }
    return ans;
}
int main()
{
    int n, t;
    cin >> n;
    vector<int> ratings;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        ratings.push_back(t);
    }
    cout << candy(ratings) << endl;
    return 0;
}