#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,a[maxn],b[maxn];
bool visited[maxn];
void dfs(int v){
	visited[v]=1;
	for(int i=0;i<n;i++){
		if(a[i]==v && !visited[b[i]]) dfs(b[i]);
		else if(b[i]==v && !visited[a[i]]) dfs(a[i]);
	}
}
bool judge(){
	for(int i=0;i<maxn;i++){
		if(!visited[i]) {
		return false;}
	}
	return true;
}
int main(){
	memset(visited,1,sizeof(visited));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		visited[a[i]]=visited[b[i]]=0;
	}
	dfs(a[0]);
	if(judge()) cout<<"Connected!!"<<endl;
	else cout<<"Not connected!!"<<endl;
	return 0;
}
