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

bool judge(TreeNode* left, TreeNode* right)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left || !right || left->val != right->val)
    {
        return false;
    }
    return judge(left->left, right->right) && judge(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root ? judge(root->left, root->right) : true;
}