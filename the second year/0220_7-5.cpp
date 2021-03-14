#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn];
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	while(k--){
		stack<int> s;
		int t=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			s.push(i);
			while(s.size()<=m && !s.empty() && s.top()==a[t]){
				s.pop();
				t++;
			}
		}
		if(s.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
