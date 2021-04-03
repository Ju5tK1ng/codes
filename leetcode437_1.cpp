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

int calPathSum(TreeNode* root, int sum)
{
    if (!root)
    {
        return 0;
    }
    int cnt = root->val == sum ? 1 : 0;
    cnt += calPathSum(root->left, sum - root->val);
    cnt += calPathSum(root->right, sum - root->val);
    return cnt;
}

int pathSum(TreeNode* root, int sum) {
    return root ? calPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
}