#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,a[30],b[30];
	while(cin>>n){
		memset(a,0,sizeof(a));
		a[0]=b[0]=1;
		for(int i=0;i<n;i++){
			cout<<b[0];
			for(int j=1;j<=i;j++){
				cout<<" ";
				if(j==1){
					b[1]=a[0]+a[1];
					cout<<b[1];
				}else if(j==i){
					b[j]=1;
					cout<<b[j];
				}else{
					b[j]=a[j]+a[j-1];
					cout<<b[j];
				}
			}
			for(int j=1;j<=i;j++){
				a[j]=b[j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
