#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int n,a[maxn];
void post_order(int i){
	if(a[i]){
		post_order(i<<1);
		post_order(i<<1|1);
		if(i!=1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==-1) a[i]=0; 
	}
	if(!a[1]) cout<<"Empty tree!!"<<endl;
	else post_order(1);
	return 0;
}
