#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,m;
	bool a[21];
	while(cin>>n>>k>>m){
		memset(a+1,1,n);
		int cnt=n,i=1,j=n;
		while(cnt){
			int t1=k,t2=m;
			for(;;i++){
				if(i>n) i-=n;
				if(a[i]) t1--;
				if(t1==0){
					a[i]=0;
					cnt--;
					printf("%3d",i);
					break;
				}
			}
			for(;;j--){
				if(j<1) j+=n;
				if(a[j] || j==i) t2--;
				if(t2==0){
					if(a[j]){
						a[j]=0;
						cnt--;
						printf("%3d",j);
						break;
					}
					break;
				}
			}
			if(cnt) cout<<",";
		}
	}
	return 0;
}
