#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<pair<TreeNode*, int>> fa(1010, make_pair(nullptr, -1));

class Solution
{
public:
    void pre(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            fa[root->left->val] = make_pair(root, 0);
            pre(root->left);
        }
        if (root->right)
        {
            fa[root->right->val] = make_pair(root, 1);
            pre(root->right);
        }
    }

    bool find(int x, int y)
    {
        if (!fa[x].first)
        {
            return false;
        }
        if (fa[x].first->val == y)
        {
            return true;
        }
        return find(fa[x].first->val, y);
    }

    TreeNode *solve(TreeNode *root, vector<vector<int>> &b)
    {
        fill(fa.begin(), fa.end(), make_pair(nullptr, -1));
        pre(root);
        for (vector<int>& v : b)
        {
            if (v[0] != v[1] && !find(v[0], v[1]) && !find(v[1], v[0]))
            {
                if (fa[v[0]].second == 0 && fa[v[1]].second == 0)
                {
                    swap(fa[v[0]].first->left, fa[v[1]].first->left);
                }
                else if (fa[v[0]].second == 0 && fa[v[1]].second == 1)
                {
                    swap(fa[v[0]].first->left, fa[v[1]].first->right);
                }
                else if (fa[v[0]].second == 1 && fa[v[1]].second == 0)
                {
                    swap(fa[v[0]].first->right, fa[v[1]].first->left);
                }
                else if (fa[v[0]].second == 1 && fa[v[1]].second == 1)
                {
                    swap(fa[v[0]].first->right, fa[v[1]].first->right);
                }
                swap(fa[v[0]], fa[v[1]]);
            }
        }
        return root;
    }
};
