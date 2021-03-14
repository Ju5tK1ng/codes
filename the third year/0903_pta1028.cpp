#include<bits/stdc++.h>
using namespace std;
struct People{
	string name;
	int year,month,date;
	bool operator<(const People& t)const{
		if(year==t.year && month==t.month){
			return date<=t.date;
		}
		else if(year==t.year){
			return month<=t.month;
		}
		else{
			return year<=t.year;
		}
	}
}p[100010];
int main(){
	People tp,youngp,oldp;
	youngp.year=2014,youngp.month=9,youngp.date=6;
	oldp.year=1814,oldp.month=9,oldp.date=6;
	int N,cnt=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tp.name;
		scanf("%d/%d/%d",&tp.year,&tp.month,&tp.date);
		if(oldp<tp && tp<youngp){
			p[cnt++]=tp;
		}
	}
	sort(p,p+cnt);
	if(cnt) cout<<cnt<<' '<<p[0].name<<' '<<p[cnt-1].name<<endl;
	else cout<<cnt<<endl;
	return 0;
}
