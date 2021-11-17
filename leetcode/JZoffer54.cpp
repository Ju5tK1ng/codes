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

class Solution {
private:
    int cnt, ans;
public:
    void reverseInOrder(TreeNode* node)
    {
        if (!node)
        {
            return;
        }
        reverseInOrder(node->right);
        cnt--;
        if (cnt == 0)
        {
            ans = node->val;
        }
        reverseInOrder(node->left);
    }

    int kthLargest(TreeNode* root, int k) {
        cnt = k;
        reverseInOrder(root);
        return ans;
    }
};
