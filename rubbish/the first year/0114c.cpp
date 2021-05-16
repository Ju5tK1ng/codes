#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000];
int lcm(int maxn,int minn){
	int M=maxn,m=minn;
	while(maxn%minn!=0 && minn!=1){
		int t=minn;
		minn=maxn%t;
		maxn=t;
	}
	return M*(m/minn);
}
int main(){
	int n,ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-2;i>=0;i--){
		ans=lcm(ans,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
