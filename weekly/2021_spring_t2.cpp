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
	vector<int> dfs(TreeNode* root, int k){
		if (root == nullptr)
		{
			return vector<int>(1, 0);
		}
		vector<int> left = dfs(root->left, k);
		vector<int> right = dfs(root->right, k);
		vector<int> ans(min(k + 1, int(left.size() + right.size())), 0);
		for (int i = 0; i < left.size(); i++)
		{
			for (int j = 0; j < right.size(); j++)
			{
				ans[0] = max(ans[0], left[i] + right[j]);
				if (i + j + 1 <= k)
				{
					ans[i + j + 1] = max(ans[i + j + 1], left[i] + right[j] + root->val);
				}
			}
		}
		return ans;
	}
    int maxValue(TreeNode* root, int k) {
		vector<int> ans=dfs(root,k);
		return *max_element(ans.begin(), ans.end());
    }
};

// 1.1
class Solution {
public:
	void dfs(TreeNode* root, int* dp, int k){
		if (root == nullptr)
		{
			return;
		}
		int left[11] = {0}, right[11] = {0};
		dfs(root->left, left, k);
		dfs(root->right, right, k);
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				dp[0] = max(dp[0], left[i] + right[j]);
				if (i + j + 1 <= k)
				{
					dp[i + j + 1] = max(dp[i + j + 1], left[i] + right[j] + root->val);
				}
			}
		}
		return;
	}
    int maxValue(TreeNode* root, int k) {
		int dp[11] = {0}, ans = 0;
		dfs(root, dp, k);
		for (int i = 0; i <= k; i++)
		{
			ans = max(ans, dp[i]);
		}
		return ans;
    }
};