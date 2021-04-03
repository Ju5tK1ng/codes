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
unordered_map<int, int> prefix;

int calPathSum(TreeNode* root, int& sum, int cur)
{
    if (!root)
    {
        return 0;
    }
    cur += root->val;
    int cnt = prefix.count(cur - sum)? prefix[cur - sum] : 0;
    prefix[cur]++;
    cnt += calPathSum(root->left, sum, cur);
    cnt += calPathSum(root->right, sum, cur);
    prefix[cur]--;
    return cnt;
}

int pathSum(TreeNode* root, int sum) {
    prefix[0] = 1;
    return calPathSum(root, sum, 0);
}