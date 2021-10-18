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

// 1.0
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool end = false;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left && !end)
            {
                q.push(node->left);
            }
            else if (!node->left && !end)
            {
                end = true;
            }
            else if (node->left && end)
            {
                return false;
            }
            if (node->right && !end)
            {
                q.push(node->right);
            }
            else if (!node->right && !end)
            {
                end = true;
            }
            else if (node->right && end)
            {
                return false;
            }
        }
        return true;
    }
};

// 1.1
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool end = false;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node)
            {
                if (!end)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                end = true;
            }
        }
        return true;
    }
};
