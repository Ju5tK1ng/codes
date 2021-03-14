#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10010],index=0,minus=0,isIndex=0,cnt=0;
	char t;
	while((t=getchar())!='\n'){
		if(t=='-'){
			if(!isIndex){
				cout<<'-';
			}
			if(isIndex){
				minus=1;
			}
		}
		if(t=='E') isIndex=1;
		if(!isIndex){
			if(t>='0' && t<='9'){
				a[cnt++]=t-'0';
			}
		}
		else{
			if(t>='0' && t<='9'){
				index=index*10+(t-'0');
			}
		}
	}
	if(minus==1){
		cout<<"0.";
		for(int i=1;i<index;i++){
			cout<<0;
		}
		for(int i=0;i<cnt;i++){
			cout<<a[i];
		}
	}
	else{
		if(index>=cnt-1){
			for(int i=0;i<cnt;i++){
				cout<<a[i];
			}
			for(int i=0;i<index-cnt+1;i++){
				cout<<0;
			}
		}
		else{
			for(int i=0;i<=index;i++){
				cout<<a[i];
			}
			cout<<'.';
			for(int i=index+1;i<cnt;i++){
				cout<<a[i];
			}
		}
	}
	cout<<endl;
	return 0;
}
