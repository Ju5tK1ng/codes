#include <iostream>
#include "complex.h"

using namespace std;

ostream&
operator << (ostream& os, const complex& x) // 若写成成员函数，则使用方法为 c1 << cout, 因为操作符作用于左边
{
  return os << '(' << real (x) << ',' << imag (x) << ')';
}

int main()
{
  complex c1(2, 1);
  complex c2(4, 0);

  cout << c1 << endl;
  cout << c2 << endl;

  cout << c1+c2 << endl;
  cout << c1-c2 << endl;
  cout << c1*c2 << endl;
  cout << c1 / 2 << endl;

  cout << conj(c1) << endl;
  cout << norm(c1) << endl;
  cout << polar(10,4) << endl;

  cout << (c1 += c2) << endl;

  cout << (c1 == c2) << endl;
  cout << (c1 != c2) << endl;
  cout << +c2 << endl;
  cout << -c2 << endl;

  cout << (c2 - 2) << endl;
  cout << (5 + c2) << endl;

  return 0;
}
