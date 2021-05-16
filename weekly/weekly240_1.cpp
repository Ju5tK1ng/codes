#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size(), ans = 0, cnt = 0, year;
        vector<int> b, d;
        for (int i = 0; i < n; i++)
        {
            b.push_back(logs[i][0]);
            d.push_back(logs[i][1]);
        }
        sort(b.begin(), b.end());
        sort(d.begin(), d.end());
        int i = 0, j = 0;
        while (i < n)
        {
            if (b[i] < d[j])
            {
                cnt++;
                if (cnt > ans)
                {
                    ans = cnt;
                    year = b[i];
                }
                i++;
            }
            else if (b[i] > d[j])
            {
                cnt--;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return year;
    }
};

// 2.0
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int offset = 1950;
        int n = logs.size(), ans = 0, cnt = 0, year;
        vector<int> d(101, 0);
        for (int i = 0; i < n; i++)
        {
            d[logs[i][0] - offset]++;
            d[logs[i][1] - offset]--;
        }
        for (int i = 0; i < 101; i++)
        {
            cnt += d[i];
            if (cnt > ans)
            {
                ans = cnt;
                year = i;
            }
        }
        return year + offset;
    }
};
