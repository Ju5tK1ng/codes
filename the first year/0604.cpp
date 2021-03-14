#include <iostream>
using namespace std;
class A {
protected:
	static int iCounter;
	int iNo;
public:
	A() {
		iNo = iCounter++;
		cout << iNo << " A constructed." << endl;
	}
	virtual ~A() {
		cout<<iCounter<<endl;
		cout << iNo << " A destructed." << endl;
	}
};
int A::iCounter = 0;
class B: public A {
public:
	B() {
		cout << iNo << " B constructed." << endl;
	}
	~B() {
		cout << iNo << " B destructed." << endl;
	}
};
int main() {
	A a;
	B b;
	return 0;
}
