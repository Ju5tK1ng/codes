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
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
            if (node)
            {
                if (node->right)
                {
                    s.push(node->right);
                }
                s.push(node);
                s.push(nullptr);
                if (node->left)
                {
                    s.push(node->left);
                }
            }
            else
            {
                ans.push_back(s.top()->val);
                s.pop();
            }
        }
        return ans;
    }
};

// 3.0
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = root, *cur = nullptr;
        while (pre)
        {
            cur = pre->left;
            if (cur)
            {
                while(cur->right && cur->right != pre)
                {
                    cur = cur->right;
                }
                if (!cur->right)
                {
                    cur->right = pre;
                    pre = pre->left;
                    continue;
                }
                else
                {
                    cur->right = nullptr;
                }
            }
            ans.push_back(pre->val);
            pre = pre->right;
        }
        return ans;
    }
};