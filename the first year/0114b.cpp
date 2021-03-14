#include<iostream>
using namespace std;
const int m=1000000007;
long long ans(long long a, long long b) {
    long long s=1;
    while(b>0){
    	if(b%2==1){
    		s=s%m;
    		a=a%m;
    		s=s*a;
		}
		a=a%m;
		a=a*a;
		b=b/2;
	}
	return s%m;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<ans(a,b)<<endl;
}
