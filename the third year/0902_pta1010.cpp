#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	bool start=true;
	while(cin.peek()!='\n'){
		cin>>a>>b;
		if(start){
			start=false;
			if(a*b!=0) cout<<a*b<<' '<<b-1;
            else cout<<a*b<<' '<<b;
		}else{
			if(a*b!=0) cout<<' '<<a*b<<' '<<b-1;
		}
	}
	cout<<endl;
	return 0;
}
