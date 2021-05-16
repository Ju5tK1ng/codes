#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int lose=0;
	for(int i=0;i<1000;i++){
		int money=0,ante=1,cnt=0;
		while(money<1000000){
			int result=0;
			while(!result){
				result=rand()%2;
				cnt++;
				if(!result){
					money-=ante;
					ante*=2;
				}else{
					money+=ante;
					ante=1;
				}
//				cout<<cnt<<":"<<money<<endl;
				if(money<-40000){
					lose++;
					goto label;
				}
			}
		}
		label:;
	}
	cout<<"lose times:"<<lose<<endl;
	return 0;
}
