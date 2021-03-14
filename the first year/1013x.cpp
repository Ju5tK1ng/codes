#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int m,n,i,j,x,is,cnt,a[100][100];
	double xk,xs,pj[100];
	while(cin>>n>>m){
		cnt=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>x;
				a[i][j]=x;
			}
		}
		for(i=0;i<n;i++){
			xs=0;
			for(j=0;j<m;j++){
				xs+=a[i][j];
			}
			if(i>0){
				cout<<" ";
			}
			printf("%.2lf",xs/m);
		}
		cout<<endl;
		for(j=0;j<m;j++){
			xk=0;
			for(i=0;i<n;i++){
				xk+=a[i][j];
			}
			if(j>0){
				cout<<" ";
			}
			printf("%.2lf",xk/n);
			pj[j]=xk/n;
		}
		cout<<endl;
		for(i=0;i<n;i++){
			is=1;
			for(j=0;j<m;j++){
				if(a[i][j]<pj[j]){
					is=0;
					break;
				}
			}
			if(is){
				cnt++;
			}
		}
		cout<<cnt<<endl<<endl;
	}
	return 0;
}
