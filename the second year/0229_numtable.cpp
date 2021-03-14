#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn];
vector<int> b;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b.push_back(a[i]+a[j]);
		}
	}
	sort(b.begin(),b.end());
	int l=b.size();
	for(int i=0;i<l;i++){
		if(i!=l-1) cout<<b[i]<<' ';
		else cout<<b[i]<<endl;
	}
	return 0;
}
