#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int l,r,suml=0,sumr=0,k=10;
	cin>>l>>r;
	l-=1;
	while(l*10/k){
		if(l%k/(k/10)<2) suml+=l/k*k/10;
		else if(l%k/(k/10)==2) suml+=l/k*k/10+l%(k/10)+1;
		else suml+=(l/k+1)*k/10;
		k*=10;
	}
	k=10;
	while(r*10/k){
		if(r%k/(k/10)<2) sumr+=r/k*k/10;
		else if(r%k/(k/10)==2) sumr+=r/k*k/10+r%(k/10)+1;
		else sumr+=(r/k+1)*k/10;
		k*=10;
	}
	cout<<sumr-suml;
	return 0;
}
