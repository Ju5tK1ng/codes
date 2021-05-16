#include<bits/stdc++.h>
using namespace std;
set<int> s[60],ans;
int n,m,k;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int t;
			scanf("%d",&t);
			s[i].insert(t);
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		set_intersection(s[x].begin(),s[x].end(),s[y].begin(),s[y].end(),inserter(ans,ans.begin()));
		printf("%.2f%%\n",100.0*ans.size()/(s[x].size()+s[y].size()-ans.size()));
		ans.clear();
	}
	return 0;
}
