#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,k,a[100000],sum;
	while(cin>>n>>k){
		sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i]/10;
			a[i]%=10;
		}
		sort(a,a+n);
		for(int i=n-1;i>=0;i--){
			if(a[i]+k<10){
				break;
			}else{
				sum++;
				k=a[i]+k-10;
			}
			if(i==0){
				sum+=k/10;
			}
			if(sum>n*10){
				sum=n*10;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
