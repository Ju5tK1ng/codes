#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int x=0,y=0,tot=1,a[20][20],n;
	memset(a,0,sizeof(a));
	cin>>n;
	a[x=0][y=n-1]=1;
	while(tot<n*n){
		while(x+1<n&&!a[x+1][y]) a[++x][y]=++tot;
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;
		while(y+1<n&&!a[x][y+1]) a[x][++y]=++tot;
	}
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			printf("%4d",a[x][y]);
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
