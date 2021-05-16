#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[100],b[100],cmax=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>=90&&a[i]<=140&&b[i]>=60&&b[i]<=90){
			cmax=max(cmax,++cnt);
		}else{
			cnt=0;
		}
	}
	cout<<cmax<<endl;
	return 0;
}
