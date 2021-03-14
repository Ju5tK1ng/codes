#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[360][360];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
		}
	}
	sort(a[n]+1,a[n]+n+1);
	cout<<a[n][n]<<endl;
	return 0;
}
