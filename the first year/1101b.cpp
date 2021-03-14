#include<iostream>
using namespace std;
int main()
{
	int num,cnt,t,ans;
	cin>>num;
	t=num;
	while(t){
	t/=10;
	cnt++;
	}
	for(int i=num-cnt*9;i<=num;i++){
		ans=t=i;
		while(t){
			ans+=t%10;
			t/=10;
		}
		if(ans==num){
			cout<<i<<endl;
			break;
		}
		if(i==num){
			cout<<0<<endl;
		}
	}
	return 0;
}
