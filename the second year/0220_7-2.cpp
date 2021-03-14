#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int c=0;
	while(q.size()!=1){
		c++;
		int t=q.front();
		q.pop();
		if(c%3!=0) q.push(t);
	}
	cout<<q.front()<<endl;
	return 0;
}
