#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,ans[100000],len=1,sum[100000]={0};
	ans[1]=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=len;j++){
			ans[j]=ans[j]*i+x;
			x=ans[j]/10;
			ans[j]%=10;
		}
		while(x){
			ans[++len]=x%10;
			x/=10;
		}
		x=0;
		for(int j=1;j<=len;j++){
			sum[j]+=ans[j]+x;
			x=sum[j]/10;
			sum[j]%=10;
		}
		if(!x) sum[len+1]=x;
	}
	if(sum[len+1]) len++;
	for(int i=len;i>0;i--){
		cout<<sum[i];
	}
	return 0;
}
