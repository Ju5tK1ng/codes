#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
	int r,n;
	while(cin>>r>>n){
		if(r==-1 && n==-1) break;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int cnt=0;
		for(int i=0;i<n;){
			int m=a[i]+r;
			while(a[i]<=m && i<n){
				i++;
			}
			m=a[i-1]+r;
			while(a[i]<=m && i<n){
				i++;
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
