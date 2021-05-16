#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn],cnt=0;
int binary_search(int x,int left,int right){
	if(left>right) return -1;
	cnt++;
	int mid=(left+right)/2;
	if(x==a[mid]) return mid;
	if(x<a[mid]) return binary_search(x,left,mid-1);
	else return binary_search(x,mid+1,right);
}
int main(){
	int n,x,ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	ans=binary_search(x,0,n-1);
	cout<<ans<<endl<<cnt<<endl;
	return 0;
}
