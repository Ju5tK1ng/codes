#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int a[maxn][maxn],b[maxn][maxn];
int main(){
	int m1,n1,m2,n2;
	cin>>m1>>n1;
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cin>>m2>>n2;
	for(int i=0;i<m2;i++){
		for(int j=0;j<n2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<m1;i++){
		for(int j=0;j<n2;j++){
			int c=0;
			for(int k=0;k<n1;k++){
				c+=a[i][k]*b[k][j];
			}
			cout<<c;
			if(j!=n2-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
