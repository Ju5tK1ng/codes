#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
priority_queue<int,vector<int>,greater<int> > q;
int a[maxn];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n/2;i<n;i++){
		q.push(a[i]);
	}
	while(k--){
		int t=q.top();
		q.pop();
		q.push(++t);
	}
	cout<<q.top()<<endl;
	return 0;
}
