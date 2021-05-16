#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int pro,a,b,i,j,n,t;
	while(cin>>n){
		cin>>pro;
		for(i=1;i<n;i++){
			cin>>a;
			b=pro;
			if(a>b){
				t=pro;
				pro=b=a;
				a=t;
			}
			for(j=2;j<=a;j++){
				while(b%j==0&&a%j==0){
					a/=j;
					b/=j;
				}
			}
			pro*=a;
		}
		cout<<pro<<endl;
	}
	return 0;
}
