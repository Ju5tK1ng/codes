#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn];
void merge_sort(int l,int r){
	if(l<r){
		int m=(l+r)/2;
		merge_sort(l,m);
		merge_sort(m+1,r);
		vector<int> v;
		int i=l,j=m+1;
		while(i<=m && j<=r){
			if(a[i]<=a[j]) v.push_back(a[i++]);
			else v.push_back(a[j++]);
		}
		while(i<=m) v.push_back(a[i++]);
		while(j<=r) v.push_back(a[j++]);
		for(int i=l;i<=r;i++) a[i]=v[i-l];
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	merge_sort(0,n-1);
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
