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
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& m)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (m.count(root))
        {
            return m[root];
        }
        int money = root->val;
        if (root->left != nullptr)
        {
            money += rob(root->left->left, m) + rob(root->left->right, m);
        }
        if (root->right != nullptr)
        {
            money += rob(root->right->left, m) + rob(root->right->right, m);
        }
        money = max(money, rob(root->left, m) + rob(root->right, m));
        m[root] = money;
        return money;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return rob(root, m);
    }
};

// 2.0
class Solution {
public:
    vector<int> dfs(TreeNode* root)
    {
        vector<int> ans(2, 0);
        if (root == nullptr)
        {
            return ans;
        }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = root->val + left[0] + right[0];
        return ans;
    }

    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};

// 2.1
class Solution {
public:
    pair<int, int> dfs(TreeNode* root)
    {
        pair<int, int> ans(0, 0);
        if (root == nullptr)
        {
            return ans;
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        ans.first = max(left.first, left.second) + max(right.first, right.second);
        ans.second = root->val + left.first + right.first;
        return ans;
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};