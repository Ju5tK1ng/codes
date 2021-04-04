#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}; 
TreeNode* solve(TreeNode* root) {
    vector<TreeNode*> v;
    v.push_back(nullptr);
    v.push_back(root);
    int cnt = 1;
    bool ok = false;
    while(true)
    {
        for (int i = cnt; i <= cnt * 2 - 1; i++)
        {
            if (v[i] == nullptr)
            {
                ok = true;
                break;
            }
            // cout << v[i]->val << endl;
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
            cout << v.size() << endl;
        }
        if (ok)
        {
            break;
        }
        cnt *= 2;
    }
    for (int i = cnt / 2; i <= cnt - 1; i++)
    {
        v[i]->left = nullptr;
        v[i]->right = nullptr;
    }
    return root;
}
int main()
{
    TreeNode* root = new TreeNode();
    root->val = 1;
    root->left = new TreeNode();
    root->right = new TreeNode();
    root->left->left = new TreeNode();
    root = solve(root);
    if (root->left) cout << 1;
    if (root->right) cout << 2;
    if (root->left->left) cout << 3;
    cout << root->val << endl << root->left->val << endl;
}