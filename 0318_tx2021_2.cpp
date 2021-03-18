#include<bits/stdc++.h>
using namespace std;
vector<int> findBuilding(vector<int>& heights) {
    vector<int> ans;
    stack<int> stl, str;
    for (int i = 0; i < heights.size(); i++)
    {
    	ans.push_back(stl.size());
    	while (!stl.empty() && stl.top() <= heights[i])
    	{
    		stl.pop();
		}
		stl.push(heights[i]);
	}
	for (int i = heights.size() - 1; i >= 0; i--)
    {
    	ans[i] += str.size() + 1;
    	while (!str.empty() && str.top() <= heights[i])
    	{
    		str.pop();
		}
		str.push(heights[i]);
	}
	return ans;
}
int main()
{
	vector<int> heights,ans;
	int t;
	while (cin >> t)
	{
		if (t == -1) break;
		else heights.push_back(t);
	}
	ans = findBuilding(heights);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
