#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,a[maxn],b[maxn];
vector <int> ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int na=0,nb=0,cnt=-1;
	while(na<n && nb<n){
		if(a[na]>b[nb]){
			if(ans.empty() || b[nb]>ans[cnt]){
				cnt++;
				ans.push_back(b[nb]);
			}
			nb++;
		}
		else if(a[na]<b[nb]){
			if(ans.empty() || a[na]>ans[cnt]){
				cnt++;
				ans.push_back(a[na]);
			}
			na++;
		}
		else{
			if(ans.empty() || a[na]>ans[cnt]){
				cnt++;
				ans.push_back(a[na]);
			}
			na++;
			nb++;
		}
	}
	while(na<n){
		if(a[na]>ans[cnt]){
				cnt++;
				ans.push_back(a[na]);
			}
		na++;
	}
	while(nb<n){
		if(b[nb]>ans[cnt]){
				cnt++;
				ans.push_back(b[nb]);
			}
		nb++;
	}
	cout<<ans[cnt/2]<<endl;
	return 0;
}
