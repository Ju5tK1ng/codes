#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a1,a2,b1,b2,acnt=0,bcnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1>>a2>>b1>>b2;
		if(a2==a1+b1 && b2==a1+b1){
			continue;
		}
		else if(a2==a1+b1){
			bcnt++;
		}
		else if(b2==a1+b1){
			acnt++;
		}
	}
	cout<<acnt<<' '<<bcnt<<endl;
	return 0;
}
