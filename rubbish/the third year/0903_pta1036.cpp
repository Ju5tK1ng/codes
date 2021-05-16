#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	char c;
	cin>>n>>c;
	m=(n+1)/2;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 || i==m-1 || j==0 || j==n-1) cout<<c;
			else cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
