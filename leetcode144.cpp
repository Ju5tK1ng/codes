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
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if (!root)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (root)
        {
            s.push(root);
        }
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right)
            {
                s.push(node->right);
            }
            if (node->left)
            {
                s.push(node->left);
            }
        }
        return ans;
    }
};

// 3.0
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = root, *cur = nullptr;
        while (pre)
        {
            cur = pre->left;
            if (cur)
            {
                while (cur->right && cur->right != pre)
                {
                    cur = cur->right;
                }
                if (!cur->right)
                {
                    cur->right = pre;
                    ans.push_back(pre->val);
                    pre = pre->left;
                }
                else
                {
                    cur->right = nullptr;
                }
            }
            else
            {
                ans.push_back(pre->val);
            }
            pre = pre->right;
        }
        return ans;
    }
};