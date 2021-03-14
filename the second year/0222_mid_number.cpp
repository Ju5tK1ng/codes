#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=200010;
const ll sup=1e10;
ll a[maxn],n,k;
bool check(ll mid){
	ll sum=0;
	for(int i=n/2;i<n;i++){
		if(a[i]<mid){
			sum+=mid-a[i];
			if(sum>k) return false;
		}
	}
	return true;
}
int main(){
	while(cin>>n>>k){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll l=0,r=sup,ans;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
