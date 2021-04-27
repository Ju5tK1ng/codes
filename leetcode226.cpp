#include<bits/stdc++.h>
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
    void swapNode(TreeNode* &left, TreeNode* &right)
    {
        if (left)
        {
            swapNode(left->left, left->right);
        }
        if (right)
        {
            swapNode(right->left, right->right);
        }
        swap(left, right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {
            swapNode(root->left, root->right);
        }
        return root;
    }
};
// 1.1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

// 2.0
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            swap(q.front()->left, q.front()->right);
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        return root;
    }
};