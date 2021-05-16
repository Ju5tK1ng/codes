#include<iostream>
using namespace std;
int main()
{
	int m,n,a[100],cnt=0;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m-=a[i];
		if(m<0){	
			m+=a[i];
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
