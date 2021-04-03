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

// 2.0
bool isSymmetric(TreeNode* root) {
    if (!root)
    {
        return true;
    }
    queue<TreeNode*> ql, qr;
    ql.push(root->left);
    qr.push(root->right);
    while (!ql.empty())
    {
        if (!ql.front() && !qr.front())
        {
        }
        else if (!ql.front() || !qr.front() || ql.front()->val != qr.front()->val)
        {
            return false;
        }
        else
        {
            ql.push(ql.front()->left);
            ql.push(ql.front()->right);
            qr.push(qr.front()->right);
            qr.push(qr.front()->left);
        }
        ql.pop();
        qr.pop();
    }
    return true;
}