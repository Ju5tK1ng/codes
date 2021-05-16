#include<bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
    vector<int> cnt;
    set<int> s;
    int ans = 0, minn = INT_MAX, maxn = INT_MIN, rsize = ratings.size();
    for (int i = 0; i < rsize; i++)
    {
        cnt.push_back(1);
        s.insert(ratings[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        for (int i = 0; i < rsize; i++)
        {
            if (*it == ratings[i])
            {
                if (i != 0 && ratings[i - 1] < ratings[i])
                {
                    cnt[i] = cnt[i - 1] + 1;
                }
                if (i != rsize - 1 && ratings[i + 1] < ratings[i])
                {
                    cnt[i] = max(cnt[i], cnt[i + 1] + 1);
                }
                ans += cnt[i];
            }
        }
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