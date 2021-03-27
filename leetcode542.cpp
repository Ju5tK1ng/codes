#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m  = matrix.size(), n = matrix[0].size();
    const int maxn = 0x3f3f3f3f;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = maxn;
                if (j != 0)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                }
                if (i != 0)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                }
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                if (j != n - 1)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                }
                if (i != m - 1)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i + 1][1] + 1);
                }
            }
        }
    }
    return matrix;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        matrix.push_back(v);
    }
    vector<vector<int>> ans = updateMatrix(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
            if (j != n - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
    return 0;
}