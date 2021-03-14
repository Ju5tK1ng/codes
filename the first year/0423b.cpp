#include<bits/stdc++.h>
#define maxd 100
#define BIG 10000
using namespace std;
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd][maxd],cols[maxd];
void copy(char type,int p,int q){
	if(type=='R'){
		for(int i=1;i<=c;i++){
			d[p][i]=d2[q][i];
		}
	}else{
		for(int i=1;i<=r;i++){
			d[i][p]=d2[i][q];
		}
	}
}
void del(char type){
	memcpy(d2,d,sizeof(d));
	int cnt=type=='R'?r:c,cnt2=0;
	for(int i=1;i<=cnt;i++){
		if(!cols[i]) copy(type,++cnt2,i);
	}
	if(type=='R') r=cnt2;
	else c=cnt2;
}
void ins(char type){
	memcpy(d2,d,sizeof(d));
	int cnt=type=='R'?r:c,cnt2=0;
	for(int i=1;i<=cnt;i++){
		if(cols[i]) copy(type,++cnt2,0);
		copy(type,++cnt2,i);
	}
	if(type=='R') r=cnt2;
	else c=cnt2;
}
int main(){
	int r1,c1,r2,c2,q,kase=0;
	char cmd[10];
	memset(d,0,sizeof(d));
	while(cin>>r>>c>>n && r){
		int r0=r,c0=c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				d[i][j]=i*BIG+j;
			}
		}
		while(n--){
			cin>>cmd;
			if(cmd[0]=='E'){
				cin>>r1>>c1>>r2>>c2;
				swap(d[r1][c1],d[r2][c2]);
			}else{
				int a,x;
				cin>>a;
				memset(cols,0,sizeof(cols));
				for(int i=0;i<a;i++){
					cin>>x;
					cols[x]=1;
				}
				if(cmd[0]=='D') del(cmd[1]);
				else ins(cmd[1]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				ans[d[i][j]/BIG][d[i][j]%BIG]=i*BIG+j;
			}
		}
		if(kase>0) cout<<endl;
		cout<<"Spreadsheet #"<<++kase<<endl;
		cin>>q;
		while(q--){
			cin>>r1>>c1;
			cout<<"Cell data in ("<<r1<<","<<c1<<")";
			if(ans[r1][c1]==0) cout<<"Gone"<<endl;
			else cout<<"moved to ("<<ans[r1][c1]/BIG<<","<<ans[r2][c2]%BIG<<")"<<endl;
		}
	}
	return 0;
}
