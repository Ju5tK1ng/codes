#include<bits/stdc++.h>
using namespace std;
int sum(int* a,int n){
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i];
	}
	return ans;
}
int sum2(int* begin,int* end){
	int ans=0;
	for(int i=0;i<end-begin;i++){
		ans+=begin[i];
	}
	return ans;
}
int sum3(int* begin,int* end){
	int ans=0;
	for(int* p=begin;p!=end;p++){
		ans+=*p;
	}
	return ans;
}
int main(){
	int a[]={1,2,3,4};
	cout<<sum(a+1,3)<<endl;
	cout<<sum2(a+1,a+4)<<endl<<sum3(a+1,a+4)<<endl;
	return 0;
}
