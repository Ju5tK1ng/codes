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
    void postorder(TreeNode* root, vector<int>& ans)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// 2.0
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                s.push(node);
                s.push(nullptr);
                if (node->right)
                {
                    s.push(node->right);
                }
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = root, *cur = nullptr;
        while (pre)
        {
            cur = pre->right;
            if (cur)
            {
                while (cur->left && cur->left != pre)
                {
                    cur = cur->left;
                }
                if (!cur->left)
                {
                    cur->left = pre;
                    ans.push_back(pre->val);
                    pre = pre->right;
                    continue;
                }
                else
                {
                    cur->left = nullptr;
                }
            }
            else
            {
                ans.push_back(pre->val);
            }
            pre = pre->left;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};