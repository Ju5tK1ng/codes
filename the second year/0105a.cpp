#include<bits/stdc++.h>
using namespace std;
int median3(int a[],int l,int r){
	int mid=(l+r)/2;
	if(a[l]>a[mid]) swap(a[l],a[mid]);
	if(a[l]>a[r]) swap(a[l],a[r]);
	if(a[mid]>a[r]) swap(a[mid],a[r]);
	swap(a[mid],a[r-1]);
	return a[r-1];
}
void quicksort(int a[],int l,int r){
	if(l>=r) return;
	if(l+1==r){
		if(a[l]>a[r]) swap(a[l],a[r]);
		return;
	}
	int pivot,i,j;
	pivot=median3(a,l,r);
	i=l;
	j=r-1;
	while(1){
		while(a[++i]<pivot);
		while(a[--j]>pivot);
		if(i<j) swap(a[i],a[j]);
		else break;
	}
	swap(a[i],a[r-1]);
	quicksort(a,l,i-1);
	quicksort(a,i+1,r);
}
int main(){
	int n=0,a[100000];
	while(cin>>a[n]){
		n++;	
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
