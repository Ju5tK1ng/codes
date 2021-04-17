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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            int n = q.size();
            ans.push_back(0);
            while (n--)
            {
                ans.back() = q.front()->val;
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
        }
        return ans;
    }
};

// 2.0
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans, int depth)
    {
        if (!root)
        {
            return;
        }
        if (ans.size() == depth)
        {
            ans.push_back(root->val);
        }
        dfs(root->right, ans, depth + 1);
        dfs(root->left, ans, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};