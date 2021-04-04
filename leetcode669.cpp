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

// 1.1
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root)
    {
        return nullptr;
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    if (low <= root->val && root->val <= high)
    {
        return root;
    }
    return root->left ? root->left : root->right;
}