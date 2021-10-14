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
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& m, int pl, int pr, int il)
    {
        if (pl > pr)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[pl]);
        int index = m[preorder[pl]] - il;
        node->left = buildTree(preorder, m, pl + 1, pl + index, il);
        node->right = buildTree(preorder, m, pl + index + 1, pr, il + index + 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return buildTree(preorder, m, 0, preorder.size() - 1, 0);
    }
};
