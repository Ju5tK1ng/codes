#include<iostream>
#include<cstdio>
using namespace std;
int prime[60000000];
bool is_prime[1000000010];
int primemake(int n){
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(n%i==0 && !is_prime[i]){
			prime[cnt++]=i;
			for(int j=2*i;j<=n;j+=i){
			is_prime[j]=1;
			}
		}
	}
	return cnt;
}
int main(){
	int n;
	cin>>n;
	int cnt=primemake(n);
	cout<<n<<":";
	for(int i=0;i<cnt;i++){
		while(n && n%prime[i]==0){
			cout<<" "<<prime[i];
			n/=prime[i];
		}
	}
	cout<<endl;
	return 0;
}
