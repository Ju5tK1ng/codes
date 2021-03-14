#include<bits/stdc++.h>
using namespace std;
int main(){
	double sum=1,ji=1;
	for(double i=1;i<1000;i++){
		for(double j=1;j<=i;j++){
			ji*=j;
		}
		sum=sum+1/ji;
	}
	cout<<sum<<endl;
	return 0;
}
