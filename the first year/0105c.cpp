#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,a[100000];
	while(~scanf("%d",&a[n])){
		n++;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i!=n-1) cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	return 0;
}
