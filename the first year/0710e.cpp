#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[20010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=0;
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
		a[i+1]+=a[i];
		ans+=a[i+1];
	}
	cout<<ans<<endl;
	return 0;
}
