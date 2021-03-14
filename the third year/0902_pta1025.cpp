#include<bits/stdc++.h>
using namespace std;
struct Node{
	int add,data,next;
};
Node n1[100010],n2[100010];
int head,n,k,tadd,tdata,tnext;
int main(){
	cin>>head>>n>>k;
	for(int i=0;i<n;i++){
		cin>>tadd>>tdata>>tnext;
		n1[tadd].add=tadd;
		n1[tadd].data=tdata;
		n1[tadd].next=tnext;
	}
	n2[0]=n1[head];
	int cnt;
	for(cnt=1;n2[cnt-1].next!=-1;cnt++){
		n2[cnt]=n1[n2[cnt-1].next];
	}
	for(int i=0;i<=cnt-k;i+=k){
		reverse(n2+i,n2+i+k);
	}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1) printf("%05d %d %05d\n",n2[i].add,n2[i].data,n2[i+1].add);
		else printf("%05d %d -1\n",n2[i].add,n2[i].data); 
	}
	return 0;
}
