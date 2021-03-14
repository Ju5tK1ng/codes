#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1010],b[1010],c,d,cnt=0;
	char t;
	while((t=getchar())!=' '){
		a[cnt++]=t-'0';
	}
	cin>>c;
	for(int i=0;i<cnt;i++){
		b[i]=a[i]/c;
		a[i+1]+=10*(a[i]%c);
	}
	d=a[cnt]/10;
	for(int i=0;i<cnt;i++){
		if(!(i==0 && b[0]==0 && cnt!=1)) cout<<b[i];
	}
	cout<<" "<<d<<endl;
	return 0;
} 
