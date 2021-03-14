#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    char ch;
    int flag=1;
    cin>>n;
    while((ch=getchar())!='='){
        cin>>temp;
        if(ch=='/'&&temp==0)
            flag=0;
        else{
            switch(ch){
                case'+':n+=temp;
                        break;
                case'-':n-=temp;
                        break;
                case'*':n*=temp;
                        break;
                case'/':n/=temp;
                        break;
                default:flag=0;
                        break;
            }
        }
        if(!flag) break;
    }
    if(flag) cout<<n<<endl;
    else cout<<"ERROR"<<endl;
    return 0;
}
