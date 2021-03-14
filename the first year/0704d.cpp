#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct interval{
	int start,end,e;
	bool operator <(const interval& t)const{
		if(start==t.start) return end<t.end;
		return start<t.start;
	}
}a[1010];
int dp[1010];
int main(){
	int n,m,r,ans=0;
	cin>>n>>m>>r;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a[i].start,&a[i].end,&a[i].e);
	}
	sort(a,a+m);
	for(int i=0;i<m;i++){
		dp[i]=a[i].e;
		for(int j=0;j<i;j++){
			if(a[i].start>=a[j].end+r)
			dp[i]=max(dp[i],dp[j]+a[i].e);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}
