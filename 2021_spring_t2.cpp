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
		if (root==NULL){
			vector<int> res;
			res.push_back(0);
			return res;
		}
		vector<int> vl=dfs(root->left ,k);
		vector<int> vr=dfs(root->right ,k);
		vector<int> res;
		res.resize(k+1);
		for (int i=0;i<vl.size();i++)
			for (int j=0;j<vr.size();j++){
				res[0]=max(res[0],vl[i]+vr[j]);
				if (i+j+1<=k)
					res[i+j+1]=max(res[i+j+1],vl[i]+vr[j]+root->val);
			}
		return res;
	}
    int maxValue(TreeNode* root, int k) {
		vector<int> result=dfs(root,k);
		int ans=0;
		for (int i=0;i<=result.size();i++)
			if (i<=k) ans=max(ans,result[i]);
		return ans;
    }
};