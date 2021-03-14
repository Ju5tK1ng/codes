#include<iostream>
using namespace std;

class complex{
public:
	complex(){
		r=i=0;
	}
	complex(float a,float b):r(a),i(b){
	}
	float r;
	float i;
	const complex& operator+(const complex& b){
		static complex re;
		re.r=r+b.r;
		re.i=i+b.i;
		return re;
	}
};

int main(){
	complex a(1,2);
	complex b(2,3);
	complex c=a+b;
	cout<<c.r<<c.i<<endl;
	return 0;
}
