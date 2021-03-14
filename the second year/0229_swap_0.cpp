#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],flag[maxn];
vector<int> v;
int main(){
	int n;
	cin>>n;
	int cnt=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==i){
			flag[i]=1;
			cnt--;
		}
	}
	if(a[0]!=0) cnt-=2;
	int circle=0;
	for(int i=0;i<n;i++){
		if(!flag[i]){
			int t=i;
			while(!flag[t]){
				flag[t]=1;
				t=a[t];
			}
			circle++;
		}
	}
	cnt+=circle;
	cout<<cnt<<endl; 
	return 0;
}
