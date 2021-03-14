#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,a[100000],ma,b[100000];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ma=a[n-1];
		b[n-1]=0;
		for(int i=n-2;i>=0;i--){
			if(a[i]==ma){
				b[i]=1;
			}else if(a[i]<ma){
				b[i]=ma+1-a[i];
			}else{
				b[i]=0;
			}
			ma=max(ma,a[i]);
		}
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
