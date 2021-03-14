#include<iostream>
using namespace std;
int cnt,a[20][20],h,w;
void count(int i,int j){
	if(a[i-1][j]==1 && i-1>=0){
		cnt++;
		a[i-1][j]=0;
		count(i-1,j);
	}
	if(a[i+1][j]==1 && i+1<h){
		cnt++;
		a[i+1][j]=0;
		count(i+1,j);
	}
	if(a[i][j-1]==1 && j-1>=0){
		cnt++;
		a[i][j-1]=0;
		count(i,j-1);
	}
	if(a[i][j+1]==1 && j+1<w){
		cnt++;
		a[i][j+1]=0;
		count(i,j+1);
	}
}
int main(){
	int x,y;
	char c;
	while(cin>>w>>h){
		if(w==0 && h==0) break;
		cnt=1;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>c;
				if(c=='.') a[i][j]=1;
				else if(c=='#') a[i][j]=0;
				else{
					a[i][j]=0;
					x=i;
					y=j;
				}
			}
		}
		count(x,y);
		cout<<cnt<<endl;
	}
	return 0;
}
