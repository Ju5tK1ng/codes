#include<iostream>
#include<cmath>
using namespace std;
typedef struct {double x,y;}Point;
double dist(Point a,Point b){
	return hypot(a.x-b.x,a.y-b.y);
}
int main(){
	Point a={3,6};
	Point b={6,10};
	cout<<dist(a,b)<<endl;
	return 0;
}
