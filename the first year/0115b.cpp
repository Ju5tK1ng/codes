#include<iostream>
using namespace std;
int a[100010];
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	while(n>1){
		int m=1;
		for(int i=0;i<n-1;i++){
			if(a[i]<a[i+1]){
				a[m++]=a[i+1];
			}
		}
		if(n>m) cnt++;
		else break;
		n=m;
	}
	cout<<cnt<<endl;
    return 0;
}
