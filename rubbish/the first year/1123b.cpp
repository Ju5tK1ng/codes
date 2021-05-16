#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,ta,tb,a[110],b[110],A=0;
	cin>>n>>ta>>tb;
	for(int i=0;i<ta;i++){
		cin>>a[i];
	}
	for(int i=0;i<tb;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		if(a[i%ta]==b[i%tb]) continue;
		else if(a[i%ta]==0 && b[i%tb]==2 || a[i%ta]==2 &&b[i%tb]==5 || a[i%ta]==5 && b[i%tb]==0) A++;
		else A--;
	}
	if(A>0) cout<<"A";
	else if(A==0) cout<<"draw";
	else cout<<"B";
	return 0;
}
