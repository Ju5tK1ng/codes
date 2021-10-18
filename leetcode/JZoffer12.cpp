#include <bits/stdc++.h>
using namespace std;
// lc79
class Solution {
public:
    void dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, bool& ans, int i, int j, int cnt, int m, int n)
    {
        if (ans || i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[cnt])
        {
            return;
        }
        if (cnt == word.size() - 1)
        {
            ans = true;
            return;
        }
        visited[i][j] = true;
        dfs(board, word, visited, ans, i - 1, j, cnt + 1, m, n);
        dfs(board, word, visited, ans, i, j + 1, cnt + 1, m, n);
        dfs(board, word, visited, ans, i + 1, j, cnt + 1, m, n);
        dfs(board, word, visited, ans, i, j - 1, cnt + 1, m, n);
        visited[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int m = board.size(), n = board[0].size();
        // 若不含有word中所有字母，直接返回false
        vector<int> check(128, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                check[board[i][j]]++;
            }
        }
        for (char c : word)
        {
            if (--check[c] < 0)
            {
                return ans;
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, word, visited, ans, i, j, 0, m, n);
                if (ans)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};
