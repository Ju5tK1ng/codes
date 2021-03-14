#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=2510;
struct cow{
	int l,r;
	bool operator <(const cow& t)const{
		return r>t.r;
	}
}a[maxn];
struct lotion{
	int spf,cover;
	bool operator <(const lotion& t)const{
		return spf<t.spf;
	}
}b[maxn];
bool cmp(cow x,cow y){
	return x.l<y.l;
}
int main(){
	int c,l;
	cin>>c>>l;
	for(int i=0;i<c;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	for(int i=0;i<l;i++){
		scanf("%d %d",&b[i].spf,&b[i].cover);
	}
	sort(a,a+c,cmp);
	sort(b,b+l);
	int ans=0,cnt=0;
	priority_queue<cow> q;
	for(int i=0;i<l;i++){
		while(cnt<c && a[cnt].l<=b[i].spf){
			q.push(a[cnt++]);
		}
		while(b[i].cover && !q.empty()){
			if(q.top().r>=b[i].spf){
				ans++;
				b[i].cover--;
			}
			q.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}
