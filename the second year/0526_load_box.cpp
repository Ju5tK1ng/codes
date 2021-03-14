#include<bits/stdc++.h>
using namespace std;
int n,t,cnt=0,a[1010],b[1010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		for(int j=0;j<n;j++){
			if(b[j]+t<=100){
				b[j]+=t;
				a[i]=j;
				cout<<t<<' '<<j+1<<endl;
				cnt=max(cnt,j+1);
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
