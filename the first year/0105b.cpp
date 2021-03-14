#include<bits/stdc++.h>
using namespace std;
void quicksort(int a[],int l,int r){
	if(l>=r) return;
	int pivot=a[l],i=l,j=r+1;
	while(1){
		while(a[++i]<pivot);
		while(a[--j]>pivot);
		if(i<j) swap(a[i],a[j]);
		else break;
	}
	swap(a[l],a[j]);
	quicksort(a,l,j-1);
	quicksort(a,j+1,r);
}
int main(){
	int n=0,a[100000];
	while(cin>>a[n++]){
		if(cin.get()=='\n') break;	
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
