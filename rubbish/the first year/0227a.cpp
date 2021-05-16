#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double a = 5.0000001, b = 5.0000002;
	cout <<setprecision(8)<< a << endl << b << endl << b-a << endl;
	return 0;
}
