#include <bits/stdc++.h>
using namespace std;
// 1.0
class Solution {
private:
    int ans;
public:
    int get(int x)
    {
        int cnt = 0;
        while (x)
        {
            cnt += x % 10;
            x /= 10;
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& v, int m, int n, int k, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || v[i][j] > k)
        {
            return;
        }
        v[i][j] = INT_MAX;
        ans++;
        dfs(v, m, n, k, i + 1, j);
        dfs(v, m, n, k, i, j + 1);
    }

    int movingCount(int m, int n, int k) {
        ans = 0;
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = get(i) + get(j);
            }
        }
        dfs(v, m, n, k, 0, 0);
        return ans;
    }
};

// 2.0
class Solution {
public:
    int get(int x)
    {
        int cnt = 0;
        while (x)
        {
            cnt += x % 10;
            x /= 10;
        }
        return cnt;
    }

    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (get(i) + get(j) <= k)
                {
                    if (i > 0)
                    {
                        dp[i][j] |= dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        dp[i][j] |= dp[i][j - 1];
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
