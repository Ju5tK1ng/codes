#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        bool rev = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                }
                // 1.1
                // q.front()->left = nullptr;
                // q.front()->right = nullptr;
                v[rev ? n - i - 1 : i] = q.front()->val;
                q.pop();
            }
            ans.push_back(v);
            rev = !rev;
        }
        return ans;
    }
};
