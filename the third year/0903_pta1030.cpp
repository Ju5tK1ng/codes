#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[100010],n,p,maxLen=0;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+maxLen;j<n;j++){
			if(a[j]<=a[i]*p){
				maxLen=j-i;
			}
			else break;
		}
	}
	cout<<maxLen+1<<endl;
	return 0;
}
