#include<iostream>
#include<algorithm>
using namespace std;
int A(int m,int n){
	int pdt=1;
	while(n--){
		pdt*=m;
		m--;
	}
	return pdt;
}
int C(int m,int n){
	if(n==0) return 1;
	return A(m,n)/A(n,n);
}
int main(){
	int n,s,ans;
	int a[10];
	cin>>n>>s;
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	do{
		ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i]*C(n-1,i);
		}
		next_permutation(a,a+n);
	}while(s!=ans);
	prev_permutation(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i];
		if(i!=n-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
