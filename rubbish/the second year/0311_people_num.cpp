#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;
const int maxm=510;
vector <int> association;
set <int> ans;
int n,m,people[maxn];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int k,flag=0;
		cin>>k;
		for(int j=0;j<k;j++){
			int t;
			cin>>t;
			if(i==0){
				people[t]=1;
			}
			association.push_back(t);
			if(people[t]) flag=1;
		}
		if(flag){
			for(int j=0;j<association.size();j++){
				ans.insert(association[j]);
				people[association[j]]=1;
			}
		}
		association.clear();
	}
	cout<<ans.size()<<endl;
	return 0;
}
