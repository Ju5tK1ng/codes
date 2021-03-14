#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct stop{
	int d,a;
	bool operator <(const stop& t)const{
		return a<t.a;
	}
}a[10010];
bool cmp(stop x,stop y){
	return x.d>y.d;
}
int main(){
	int n,l,p;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].d,&a[i].a);
	}
	sort(a,a+n,cmp);
	cin>>l>>p;
	int ans=0,cnt=0;
	priority_queue <stop> q;
	while(l>p){
		while(a[cnt].d>=l-p && cnt<n){
			q.push(a[cnt++]);
		}
		if(q.empty()){
			ans=-1;
			break;
		}
		else{
			p+=q.top().a;
			q.pop();
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
