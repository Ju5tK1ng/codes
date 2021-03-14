#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m,a[10010],begin,end,cnt=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		a[i]=1;
	}
	for(int i=0;i<m;i++){
		cin>>begin>>end;
		for(int j=begin;j<=end;j++){
			a[j]=0;
		}
	}
	for(int i=0;i<=n;i++){
		if(a[i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
