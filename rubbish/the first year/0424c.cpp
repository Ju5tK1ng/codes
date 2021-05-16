#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int pow(long long a,long long p,long long m){
    int ans=1;
    while(p>0){
        if(p%2==1){
            ans=ans*a%m;
            p--;
        }
        else{
            a=a*a%m;
            p/=2;
        }
    }
    return ans;
}
int main(){
	int t,a,p;
	cin>>t;
	while(t--){
		cin>>a>>p;
		cout<<pow(a,p,mod)<<endl;;	
	}
	return 0;
}
