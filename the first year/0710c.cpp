#include<iostream>
#include<cstdio>
using namespace std;
char c[2010];
int main(){
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",&c[i]);
	}
	int l=0,r=n-1;
	while(l<=r){
		int d=0;
		while(l+d<r-d && c[l+d]==c[r-d]){
			d++;
		}
		if(c[l+d]<c[r-d]){
			putchar(c[l++]);
		}
		else{
			putchar(c[r--]);
		}
		cnt++;
		if(cnt%80==0) cout<<endl;
	}
	if(cnt%80!=0) cout<<endl;
	return 0;
}
