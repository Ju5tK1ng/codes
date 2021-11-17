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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size(), l = q.front().second, r;
            while (size--)
            {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left)
                {
                    q.push(make_pair(node->left, r * 2 - l * 2));
                }
                if (node->right)
                {
                    q.push(make_pair(node->right, r * 2 + 1 - l * 2));
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
