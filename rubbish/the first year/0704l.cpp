#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct block{
	int h,a,c;
	bool operator <(const block& t)const{
		return a<t.a;
	} 
}b[410];
bool a[40010];
int used[40010];
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&b[i].h,&b[i].a,&b[i].c);
	}
	sort(b,b+k);
	int ans=0;
	a[0]=true;
	for(int i=0;i<k;i++){
		memset(used,0,sizeof(used));
		for(int j=b[i].h;j<=b[i].a;j++){
			if(!a[j] && a[j-b[i].h] && used[j-b[i].h]<b[i].c){
				a[j]=true;
				used[j]=used[j-b[i].h]+1;
				ans=max(ans,j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
