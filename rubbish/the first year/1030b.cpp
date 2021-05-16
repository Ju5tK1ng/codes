#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char num[20],str[100];
	int count=0;
	cin>>num;
	for(int abc=100;abc<=999;abc++){
		for(int de=10;de<=99;de++){
			int x=abc*(de%10),y=abc*(de/10),z=abc*de;
			sprintf(str,"%d%d%d%d%d",abc,de,x,y,z);
			int ok=1;
			for(int i=0;i<strlen(str);i++){
				if(strchr(num,str[i])==NULL) ok=0;
			}
			if(ok){
				count++;
				printf("<%d>\n",count);
				printf("%5d\nX%4d\n-----\n%5d\n%5d\n-----\n%5d\n\n",abc,de,x,y,z);
			}
		}
	}
	cout<<count;
	return 0;
}
