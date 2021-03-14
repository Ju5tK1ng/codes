#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2,ans;
	cin>>c1>>c2;
	ans=(c2-c1+50)/100;
	printf("%02d:",ans/3600);
	ans%=3600;
	printf("%02d:%02d",ans/60,ans%60);
	return 0;
}
