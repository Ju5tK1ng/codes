#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int n,a[maxn],td[maxn],bu[maxn];
void top_down(){
	for(int i=1;i<=n;i++){
		td[i]=a[i];
		int t=i;
		while(t>>1 && td[t]>td[t>>1]){
			swap(td[t],td[t>>1]);
			t/=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=n) cout<<td[i]<<" ";
		else cout<<td[i]<<endl;
	}
}
void bottom_up(int i){
	if(bu[i<<1] || bu[i<<1|1]){
		int t;
		if(bu[i<<1]>bu[i<<1|1]) t=i<<1;
		else t=i<<1|1;
		if(bu[i]<bu[t]){
			swap(bu[i],bu[t]);
			bottom_up(t);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bu[i]=a[i];
	}
	top_down();
	for(int i=n;i>0;i--){
		bottom_up(i);
	}
	for(int i=1;i<=n;i++){
		if(i!=n) cout<<bu[i]<<" ";
		else cout<<bu[i]<<endl;
	}
	return 0;
}
