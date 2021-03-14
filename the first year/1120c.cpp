#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int l,w,sx;
	char chr;
	cin>>l>>w>>chr>>sx;
	for(int i=0;i<l;i++){
		for(int j=0;j<w;j++){
			if(i>0 && i<l-1 && j>0 && j<w-1 && sx==0) cout<<" ";
			else cout<<chr;
		}
		cout<<endl;
	}
	return 0;
}
