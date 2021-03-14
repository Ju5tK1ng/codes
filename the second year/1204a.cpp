#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int n,leaf_cnt=0,tree[maxn],pre_order[maxn],in_order[maxn],ans[maxn];
int create_tree(int ps,int pe,int is,int ie,int cnt){
	if(ps>pe || is>ie) return 0;
	else{
		int pos=0;
		while(in_order[is+pos]!=pre_order[ps]) pos++;
		tree[cnt<<1]=create_tree(ps+1,ps+pos,is,is+pos-1,cnt<<1);
		tree[cnt<<1|1]=create_tree(ps+pos+1,pe,is+pos+1,ie,cnt<<1|1);
		if(!tree[cnt<<1] && !tree[cnt<<1|1]){
			ans[leaf_cnt]=pre_order[ps];
			leaf_cnt++;
		}
		return pre_order[ps];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pre_order[i];
	}
	for(int i=1;i<=n;i++){
		cin>>in_order[i];
	}
	tree[1]=create_tree(1,n,1,n,1);
	sort(ans,ans+leaf_cnt);
	for(int i=0;i<leaf_cnt;i++){
		if(i!=leaf_cnt-1) cout<<ans[i]<<" ";
		else cout<<ans[i]<<endl;
	}
	return 0;
}
