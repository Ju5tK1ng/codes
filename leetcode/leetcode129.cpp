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

// // 1.0
// class Solution {
// public:
//     vector<string> calcNumbers(TreeNode* root)
//     {
//         if (!root)
//         {
//             return {};
//         }
//         if (!root->left && !root->right)
//         {
//             return {to_string(root->val)};
//         }
//         vector<string> l = calcNumbers(root->left);
//         vector<string> r = calcNumbers(root->right);
//         vector<string> c;
//         string val = to_string(root->val);
//         for (string& s : l)
//         {
//             c.push_back(val + s);
//         }
//         for (string& s : r)
//         {
//             c.push_back(val + s);
//         }
//         return c;
//     }

//     int sumNumbers(TreeNode* root) {
//         vector<string> v = calcNumbers(root);
//         int ans = 0;
//         for (string& s : v)
//         {
//             ans += atoi(s.c_str());
//         }
//         return ans;
//     }
// };


class Solution {
private:
    int sum;
public:
    void calcNumbers(TreeNode* root, int cur)
    {
        if (!root->left && !root->right)
        {
            sum += cur;
        }
        if (root->left)
        {
            calcNumbers(root->left, cur * 10 + root->left->val);
        }
        if (root->right)
        {
            calcNumbers(root->right, cur * 10 + root->right->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        if (!root)
        {
            return sum;
        }
        calcNumbers(root, root->val);
        return sum;
    }
};
