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
    void dfs(TreeNode* root, vector<string>& ans, string t)
    {
        if (!root->left && !root->right)
        {
            t += to_string(root->val);
            ans.push_back(t);
            return;
        }
        t += to_string(root->val) + "->";
        if (root->left)
        {
            dfs(root->left, ans, t);
        }
        if (root->right)
        {
            dfs(root->right, ans, t);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string t;
        dfs(root, ans, t);
        return ans;
    }
};