#include<bits/stdc++.h>
using namespace std;
struct MoonCake{
	double num,tot,pri;
	bool operator <(const MoonCake& t)const{
		return pri>t.pri;
	}
}a[1010];
int main(){
	int n,d;
	double ans;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i].num;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].tot;
		a[i].pri=a[i].tot/a[i].num;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(d>a[i].num){
			ans+=a[i].tot;
			d-=a[i].num;
		}
		else{
			ans+=a[i].pri*d;
			break;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
