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

void inorder(TreeNode* root, TreeNode*& error1, TreeNode*& error2, TreeNode*& pre)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, error1, error2, pre);
    if (pre && pre->val > root->val)
    {
        if (!error1)
        {
            error1 = pre;
            error2 = root;
        }
        else
        {
            error2 = root;
        }
    }
    pre = root;
    inorder(root->right, error1, error2, pre);
}

void recoverTree(TreeNode* root) {
    TreeNode *error1 = nullptr, *error2 = nullptr, *pre = nullptr;
    inorder(root, error1, error2, pre);
    swap(error1->val, error2->val);
}