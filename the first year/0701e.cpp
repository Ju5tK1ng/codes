#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int a[100],n,m;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		for(int i=0;i<n;i++){
		cin>>a[i];
		}
		a[n]=m;
		sort(a,a+n+1);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
