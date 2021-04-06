#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] < target)
        {
            i++;
        }
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// 1.1
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     std::ios::sync_with_stdio(0);
//     if(matrix.size() == 1 && matrix[0].size() == 0) {
//         return false;
//     }
//     while (matrix.size() != 0) {
//         int temp = matrix[0][matrix[0].size()-1];
//         if (temp == target) {
//             return true;
//         } else if (temp > target) {
//             for (int i = 0; i < matrix.size(); i++) {
//                 matrix[i].pop_back();
//                 if (matrix[i].size() == 0) {
//                     matrix.erase(matrix.begin()+i);
//                 }
//             }
//         } else {
//             matrix.erase(matrix.begin());
//         }
//     }
//     return false;
// }

int main()
{
    int m, n, target;
    cin >> m >> n >> target;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}