#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> c[25010];
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>c[i].first>>c[i].second;
	}
	sort(c,c+n);
	int from=1,to=0,cnt=1;
	for(int i=0;i<n;i++){
		if(c[i].first>from){
			cnt++;
			from=to+1;
		}
		if(c[i].first<=from){
			to=max(to,c[i].second);
			if(to>=t) break;
		}else break;
	}
	if(to>=t) cout<<cnt<<endl;
	else cout<<-1<<endl;
	return 0;
}
