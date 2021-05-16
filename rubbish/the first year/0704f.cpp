#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int used[100010];
int a[110],c[110];
bool price[100010];
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		memset(price,0,sizeof(price));
		price[0]=true;
		int ans=0;
		for(int i=0;i<n;i++){
			memset(used,0,sizeof(used));
			for(int j=a[i];j<=m;j++){
				if(!price[j] && price[j-a[i]] && used[j-a[i]]<c[i]){
					price[j]=true;
					used[j]=used[j-a[i]]+1;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
