#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct wood{
	int l,w;
	bool operator <(const wood& t)const{
		if(l==t.l) return w<t.w;
		return l<t.l; 
	}
}w[5050];
bool used[5050];
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++){
			scanf("%d %d",&w[i].l,&w[i].w);
		}
		sort(w,w+n);
		int cnt=0,last_w;
		for(int i=0;i<n;i++){
			if(!used[i]){
				last_w=w[i].w;
				for(int j=i+1;j<n;j++){
					if(last_w<=w[j].w && !used[j]){
						last_w=w[j].w;
						used[j]=true;
					}
				}
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
