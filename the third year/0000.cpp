#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<char> v;
	string sa,sb;
	cin>>sa>>sb;
	reverse(sa.begin(),sa.end());
	reverse(sb.begin(),sb.end());
	int lena=sa.length(),lenb=sb.length();
	if(lena>lenb)
	{
		int k;
		for(k=lenb;k<lena;k++)
		    sb+='0';
	}
	else
	{
		int k;
		for(k=lena;k<lenb;k++)
		   sa+='0';
	}
	int i,j;
	for(j=0;j<sb.length();j++)
	{
		int num=0;
		if((j+1)%2)
		{
			num=sa[j]-'0'+sb[j]-'0';
			num%=13;
			if(num==10)      v.push_back('J');
			else if(num==11) v.push_back('Q');
			else if(num==12) v.push_back('K');
			else v.push_back(num+'0');
		}
		else
		{
			num=sb[j]-'0'-(sa[j]-'0');
			if(num<0) num+=10;
			v.push_back(num+'0');
		}
	}
	reverse(v.begin(),v.end());
	for(int k=0;k<v.size();k++)
	  cout<<v[k];
	cout<<endl;
}
