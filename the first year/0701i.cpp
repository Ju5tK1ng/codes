#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m,a[50][5];
	double b[5];
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			double sum=0;
			for(int j=0;j<m;j++){
				sum+=a[i][j];
			}
			sum/=m;
			printf("%.2lf",sum);
			if(i!=n-1) cout<<" ";
			else cout<<endl;
		}
		for(int j=0;j<m;j++){
			double sum=0;
			for(int i=0;i<n;i++){
				sum+=a[i][j];
			}
			b[j]=sum/n;
		}
		for(int i=0;i<m;i++){
			printf("%.2lf",b[i]);
			if(i!=m-1) cout<<" ";
			else cout<<endl;
		}
		int cnt=n;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]<b[j]){
					cnt--;
					break;
				} 
			}
		}
		cout<<cnt<<endl<<endl;
	}
	return 0;
}
