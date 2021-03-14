#include<iostream>
using namespace std;
int main(){
	int a[100],n,m;
	for(int i=0;i<100;i++){
		a[i]=(i+1)*2;
	}
	while(cin>>n>>m){
		for(int i=0;i<n;i+=m){
			if(i<n-m){
				cout<<(a[i]+a[i+m-1])/2<<" ";
			}else{
				cout<<(a[i]+a[n-1])/2<<endl;
			}
		}
	}
	return 0;
}
