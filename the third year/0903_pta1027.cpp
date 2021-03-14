#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxLen=1;
	char c;
	cin>>n>>c;
	n--;
	for(int i=3;n>i*2;i+=2){
		maxLen=i;
		n-=i*2;
	}
	for(int i=maxLen;i>=1;i-=2){
		for(int j=0;j<(maxLen-i)/2;j++){
			cout<<' ';
		}
		for(int j=0;j<i;j++){
			cout<<c;
		}
		cout<<endl;
	}
	for(int i=3;i<=maxLen;i+=2){
		for(int j=0;j<(maxLen-i)/2;j++){
			cout<<' ';
		}
		for(int j=0;j<i;j++){
			cout<<c;
		}
		cout<<endl;
	}
	cout<<n<<endl;
	return 0;
}
