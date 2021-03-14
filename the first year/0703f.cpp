#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct coin{
	int v,a;
	bool operator <(const coin& t)const{
		return v<t.v;
	}
}a[25];
int use[25];
int main(){
	int n,c,cnt=0;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].v,&a[i].a);
	}
	sort(a,a+n);
	while(1){
		int r=c;
		memset(use,0,sizeof(use));
		for(int i=n-1;i>=0;i--){
			if(a[i].a){
				int need=min(a[i].a,r/a[i].v);
				use[i]=need;
				r-=a[i].v*use[i];
			}
			if(r==0) break;
		}
		if(r){
			for(int i=0;i<n;i++){
				if(a[i].a && a[i].v>=r){
					r=0;
					use[i]++;
					break;
				}
			}
		}
		if(r) break;
		int week=99999999;
		for(int i=0;i<n;i++){
			if(use[i]) week=min(week,a[i].a/use[i]);
		}
		for(int i=0;i<n;i++){
			if(use[i]) a[i].a-=week*use[i];
		}
		cnt+=week;
	}
	cout<<cnt<<endl;
}
