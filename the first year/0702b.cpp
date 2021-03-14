#include<iostream>
using namespace std;
int mi,a[20][20],w,h;
void pan(int i,int j,int cnt){
	if(cnt>=10) return;
	int u=i,v=j;
	while(a[i-1][j]==0 && i-1>=0){
		i--;
	}
	if(a[i-1][j]==3 && i-1>=0){
		mi=min(mi,cnt+1);
	}
	if(a[i-1][j]==1 && i-1>=0 && i!=u){
		a[i-1][j]=0;
		pan(i,j,cnt+1);
		a[i-1][j]=1;
	}
	i=u;
	while(a[i+1][j]==0 && i+1<h){
		i++;
	}
	if(a[i+1][j]==3 && i+1<h){
		mi=min(mi,cnt+1);
	}
	if(a[i+1][j]==1 && i+1<h && i!=u){
		a[i+1][j]=0;
		pan(i,j,cnt+1);
		a[i+1][j]=1;
	}
	i=u;
	while(a[i][j-1]==0 && j-1>=0){
		j--;
	}
	if(a[i][j-1]==3 && j-1>=0){
		mi=min(mi,cnt+1);
	}
	if(a[i][j-1]==1 && j-1>=0 && j!=v){
		a[i][j-1]=0;
		pan(i,j,cnt+1);
		a[i][j-1]=1;
	}
	j=v;
	while(a[i][j+1]==0 && j+1<w){
		j++;
	}
	if(a[i][j+1]==3 && j+1<w){
		mi=min(mi,cnt+1);
	}
	if(a[i][j+1]==1 && j+1<w && j!=v){
		a[i][j+1]=0;
		pan(i,j,cnt+1);
		a[i][j+1]=1;
	}
}
int main(){
	int x,y;
	while(cin>>w>>h){
		if(w==0 && h==0) break;
		int cnt=0;
		mi=11;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>a[i][j];
				if(a[i][j]==2){
					a[i][j]=0;
					x=i;
					y=j;
				}
			}
		}
		pan(x,y,cnt);
		if(mi<=10) cout<<mi<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
