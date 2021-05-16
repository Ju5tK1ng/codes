#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[4],cnt=0;
	char t;
	while((t=getchar())!='\n'){
		a[cnt++]=t-'0';
	}
	while(true){
		sort(a,a+4);
		int big=a[0]+a[1]*10+a[2]*100+a[3]*1000,small=a[0]*1000+a[1]*100+a[2]*10+a[3];
		int ans=big-small;
		printf("%04d - %04d = %04d\n",big,small,ans);
		if(ans==6174 || ans==0) break;
		a[0]=ans/1000;
		ans%=1000;
		a[1]=ans/100;
		ans%=100;
		a[2]=ans/10;
		a[3]=ans%10;
	}
	return 0;
}
