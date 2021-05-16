#include<bits/stdc++.h>
using namespace std;
int b[10010][10010],cnt;
int main(){
	int n,a[100010],m;
	cin>>n;
	cnt=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n;i>=sqrt(n);i--){
		if(n%i==0) m=i;
	}
	for(int i=0;i<=n/m+1;i++){
		b[0][i]=b[m+1][i]=1;
	}
	for(int i=0;i<=m+1;i++){
		b[i][0]=b[i][n/m+1]=1;
	}
	int i=1,j=1;
	while(cnt!=-1){
		while(b[i][j]==0){
			b[i][j]=a[cnt--];
			j++;
		}
		j--;
		i++;
		while(b[i][j]==0){
			b[i][j]=a[cnt--];
			i++;
		}
		i--;
		j--;
		while(b[i][j]==0){
			b[i][j]=a[cnt--];
			j--;
		}
		j++;
		i--;
		while(b[i][j]==0){
			b[i][j]=a[cnt--];
			i--;
		}
		i++;
		j++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n/m;j++){
			if(j!=n/m) cout<<b[i][j]<<' ';
			else cout<<b[i][j]<<endl;
		}
	}
	return 0;
}
