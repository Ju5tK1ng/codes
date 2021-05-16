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

int calDiameter(TreeNode* root, int& maxd)
{
    if (!root)
    {
        return 0;
    }
    int left = calDiameter(root->left, maxd), right = calDiameter(root->right, maxd);
    maxd = max(maxd, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxd = 0;
    calDiameter(root, maxd);
    return maxd;
}