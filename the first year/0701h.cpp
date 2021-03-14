#include<iostream>
using namespace std;
int main(){
	int m,n,x,y;
	int a[100][100],b[100][100];
	while(cin>>m>>n){
		int ma=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]<0) b[i][j]=-a[i][j];
				else b[i][j]=a[i][j];
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(b[i][j]>ma){
					ma=b[i][j];
					x=i;
					y=j;
				}
			}
		}
		cout<<x+1<<" "<<y+1<<" "<<a[x][y]<<endl;
	}
	return 0;
}
