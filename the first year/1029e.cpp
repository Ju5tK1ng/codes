#include<iostream>
using namespace std;
int main(){
	int n,a[100],cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if((a[i]/1000+a[i]%1000/100+a[i]%100/10)<a[i]%10){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
