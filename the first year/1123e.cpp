#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a1[210],b1[210];
	int a[210]={0},b[210]={0},c[210]={0},lena,lenb,lenc,i,x;
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(i=0;i<lena;i++){
		a[lena-i]=a1[i]-48;
	}
	for(i=0;i<lenb;i++){
		b[lenb-i]=b1[i]-48;
	}
	lenc=1;
	x=1;
	while(lenc<=lena){
		c[lenc]=9+a[lenc]-b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	while(c[lenc]==0 && lenc!=1){
		lenc--;
	}
	for(i=lenc;i>0;i--){
		cout<<c[i];
	}
	return 0;
}
