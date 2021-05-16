#include<iostream>
#include<cstdio>
using namespace std;
int a[7];
int b[4]={0,5,3,1};
int main(){
	while(1){
		scanf("%d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
		if(!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) break;
		int n=a[4]+a[5]+a[6]+(a[3]+3)/4;
		int m2=a[4]*5+b[a[3]%4];
		if(a[2]>m2) n+=(a[2]-m2+8)/9;
		int m1=n*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
		if(a[1]>m1) n+=(a[1]-m1+35)/36;
		cout<<n<<endl;
	}
	return 0;
}
