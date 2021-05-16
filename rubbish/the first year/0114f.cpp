#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int p,a[100000];
    while(cin>>p){
    	int cnt=0;
	    for(int i=2;i<p;i++){
	    	int t=i;
	    	for(int j=0;j<p-1;j++){
	    		t%=p;
	    		a[j]=t;
	    		t*=i;
			}
			sort(a,a+p-1);
			int ok=1;
			for(int j=0;j<p-1;j++){
				if(a[j]!=j+1) ok=0;
			}
			if(ok) cnt++;
		}
	    cout<<cnt<<endl;
	}
	return 0;
}
