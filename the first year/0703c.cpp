#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=50050;
int assign[maxn];
struct node{
	int l,r,order;
	bool operator <(const node& t)const{
		return r>t.r;
	}
}a[maxn];
bool cmp(node a,node b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
priority_queue<node> q;
int main(){
	int n,cnt=1;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		a[i].order=i;
	}
	sort(a,a+n,cmp);
	q.push(a[0]);
	assign[a[0].order]=cnt;
	for(int i=1;i<n;i++){
		if(!q.empty() && q.top().r<a[i].l){
			assign[a[i].order]=assign[q.top().order];
			q.pop();
		}else{
			cnt++;
			assign[a[i].order]=cnt;
		}
		q.push(a[i]);
	}
	cout<<cnt<<endl;
	for(int i=0;i<n;i++){
		cout<<assign[i]<<endl;
	}
	return 0;
}
