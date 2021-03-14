#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,len,i,j,is;
	char s[100];
	cin>>n;
	gets(s);
	for(i=0;i<n;i++){
		gets(s);
		is=1;
		for(j=0;j<strlen(s);j++){
			if(s[i]!=s[strlen(s)-1-i]){
				is=0;
			}
		}
		if(is==1){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
