#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int start=0;
	for(int i=0;i<10;i++){
		cin>>a[i];
		if(start==0 && i!=0 && a[i]!=0) start=i;
	}
	a[start]--;
	cout<<start;
	for(int i=0;i<10;i++){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	cout<<endl;
	return 0;
}
