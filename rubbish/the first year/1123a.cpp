#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,a[3010],b[3010],ok=1;
	cin>>n>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		b[i-1]=abs(a[i]-a[i-1]);
	}
	sort(b,b+n-1);
	for(int i=0;i<n-1;i++){
		if(b[i]!=i+1){
			ok=0;
			break;
		}
	}
	if(ok) cout<<"Jolly"<<endl;
	else cout<<"Not jolly"<<endl;
	return 0;
}
