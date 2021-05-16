#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char chr[50];
	int num[50],len,ok=0;
	gets(chr);
	len=strlen(chr);
	for(int i=0;i<len;i++){
		num[len-i]=chr[i]-48;
	}
	for(int i=2;i<10;i++){
		int x=0;
		for(int j=len;j>0;j--){
			x=(num[j]+10*x)%i;
		}
		if(!x){
			if(ok) cout<<" ";
			cout<<i;
			ok=1;
		}
	}
	if(!ok) cout<<"none";
	return 0;
}
