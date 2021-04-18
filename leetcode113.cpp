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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& t)
    {
        targetSum -= root->val;
        t.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (targetSum == 0)
            {
                ans.push_back(t);
            }
            t.pop_back();
            return;
        }
        if (root->left)
        {
            dfs(root->left, targetSum, ans, t);
        }
        if (root->right)
        {
            dfs(root->right, targetSum, ans, t);
        }
        t.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> t;
        if (root)
        {
            dfs(root, targetSum, ans, t);
        }
        return ans;
    }
};