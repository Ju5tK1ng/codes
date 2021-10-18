#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// lc105
class Solution {
private:
    unordered_map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& preorder, int pl, int pr, int il)
    {
        if (pl > pr)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[pl]);
        int size = m[preorder[pl]] - il;
        node->left = buildTree(preorder, pl + 1, pl + size, il);
        node->right = buildTree(preorder, pl + size + 1, pr, il + size + 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, 0);
    }
};
