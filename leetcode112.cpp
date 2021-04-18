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
    void dfs(TreeNode* root, int targetSum, bool& ans)
    {
        if (ans)
        {
            return;
        }
        targetSum -= root->val;
        if (!root->left && !root->right)
        {
            if (targetSum == 0)
            {
                ans = true;
            }
            return;
        }
        if (root->left)
        {
            dfs(root->left, targetSum, ans);
        }
        if (root->right)
        {
            dfs(root->right, targetSum, ans);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        if (root)
        {
            dfs(root, targetSum, ans);
        }
        return ans;
    }
};