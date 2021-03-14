#include<bits/stdc++.h>
using namespace std;
char a[10][10];
int main(){
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];
	for(int i=0;i<10;i++){
		int ok=0,t;
		for(int j=0;j<10;j++){
			if(a[i][j]=='#'){
				t=j;
				ok++;			
			}
		}
		if(ok==2){
			cout<<"DOWN"<<endl;
			return 0;
		}
		if(ok==1){
			if(t<2 || a[i+1][t-1]=='.'){
				cout<<"RIGHT"<<endl;
			}else if(t>7 || a[i+1][t+1]=='.'){
				cout<<"LEFT"<<endl;
			}else cout<<"UP"<<endl;
			return 0;
		}
	}
}
