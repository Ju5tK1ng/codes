#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn];
void adjust(int i,int len){
	int t=i;
	if(i*2<len && a[t]>a[i*2]) t=i*2;
	if(i*2+1<len && a[t]>a[i*2+1]) t=i*2+1;
	if(t!=i){
		swap(a[i],a[t]);
		adjust(t,len);
	}
}
int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int mid=n/2+1;
		for(int i=1;i<=mid;i++){
			a[i]=a[i+mid-1];
		}
		while(k--){
			a[1]++;
			adjust(1,mid+1);
		}
		cout<<a[1]<<endl;
	}
	return 0;
}
