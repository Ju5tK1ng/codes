#include<iostream>
using namespace std;
bool is_prime[1000000];
int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(!is_prime[i]){
			cnt++;
			for(int j=2*i;j<=n;j+=i){
				is_prime[j]=1;
			}
		}
	}
	cout<<cnt<<endl;
	return cnt;
}
