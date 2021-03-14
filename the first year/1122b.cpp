#include<iostream>
using namespace std;
int main(){
	int n,a[10],cnt=0;
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	cin>>n;
	n+=30;
	for(int i=0;i<10;i++){
		if(a[i]<=n) cnt++;
	}
	cout<<cnt;
	return 0;
}
