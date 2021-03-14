#include<bits/stdc++.h>
using namespace std;
int n;
double d,ansd=0,ans=0;
struct MoonCake{
	double stock,price;
	bool operator <(const MoonCake& t)const{
		return price>t.price;
	}
}mk[1010];
int main(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>mk[i].stock;
	}
	for(int i=0;i<n;i++){
		cin>>mk[i].price;
		mk[i].price/=mk[i].stock;
	}
	sort(mk,mk+n);
	for(int i=0;i<n;i++){
		if(ansd+mk[i].stock<=d){
			ansd+=mk[i].stock;
			ans+=mk[i].stock*mk[i].price;
		}
		else{
			ans+=(d-ansd)*mk[i].price;
			break;
		}
	}
	printf("%.2lf",ans);
	return 0;
}
