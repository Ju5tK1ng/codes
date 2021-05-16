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

TreeNode* deleteNodes(TreeNode* root, vector<TreeNode*>& ans, unordered_set<int>& dict)
{
    if (!root)
    {
        return root;
    }
    root->left = deleteNodes(root->left, ans, dict);
    root->right = deleteNodes(root->right, ans, dict);
    if (dict.count(root->val))
    {
        if (root->left)
        {
            ans.push_back(root->left);
        }
        if (root->right)
        {
            ans.push_back(root->right);
        }
        root = nullptr;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> dict(to_delete.begin(), to_delete.end());
    root = deleteNodes(root, ans, dict);
    if (root)
    {
        ans.push_back(root);
    }
    return ans;
}