#include<bits/stdc++.h>
using namespace std;
int main(){
	wchar_t rune[26]={'?','?','?','?','?','?','?','?','?','?','k','?','?','?','?','p','?','?','?','?','?','v','?','x','y','z'};
	while(true){
		char a[1000];
		wchar_t c[1000];
		int cnt=0;
		cout<<"----------------------------"<<endl;
		cout<<"请输入原文,并以回车结束"<<endl;
		wcin>>c;
		for(int i=0;i<wcslen(c);i++){
			int t=1;
			for(int j=0;j<26;j++){
				if(c[i]==rune[j]){
					printf("%c",j+97);
					t=0;
					break;
				}
			}
			if(t) wcout<<c[i];
		}
		cout<<endl;
	}
	return 0;
}
