#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void inorder(TreeNode* root, vector<int>& ans)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    vector<int> ans;
    inorder(root, ans);
    bool ok = true;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            ok = false;
            break;
        }
    }
    cout << ok << endl;
    return 0;
}