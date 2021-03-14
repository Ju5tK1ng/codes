#include<iostream>
using namespace std;
int main(){
	int n,ans[1000],len=1;
	ans[1]=2;
	cin>>n;
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=len;j++){
			ans[j]=ans[j]*2+x;
			x=ans[j]/10;
			ans[j]%=10;
		}
		if(x){
			len++;
			ans[len]=1;
		}
	}
	for(int i=len;i>0;i--){
		cout<<ans[i];
	}
	return 0;
}
