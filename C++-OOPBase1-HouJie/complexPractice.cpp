#include <iostream>
using namespace std;

#ifndef __COMPLEX__
#define __COMPLEX__

class Complex
{
private:
    double re, im;
    friend Complex& __dapl(Complex* ths, const Complex& r);

public:
    Complex(double real = 0, double imag = 0) : re(real), im(imag) {}
    Complex& operator += (const Complex& r);
    double real() const
    {
        return re;
    }
    double imag() const
    {
        return im;
    }
};

inline Complex& __dapl(Complex* ths, const Complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline Complex& Complex::operator += (const Complex& r)
{
    return __dapl(this, r);
}

inline Complex operator + (const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

inline Complex operator - (const Complex& r)
{
    return Complex(-r.real(), -r.imag());
}

inline ostream& operator << (ostream& os, const Complex& r)
{
    if (r.imag() >= 0)
    {
        return os << "(" << r.real() << " + " << r.imag() << "i)";
    }
    else
    {
        return os << "(" << r.real() << " - " << -r.imag() << "i)";
    }
}

template <typename T>
bool IsConst(T& x)
{
    return false;
}

template <typename T>
bool IsConst(const T& x)
{
    return true;
}

#endif

int main()
{
    Complex c1(5, 2);
    Complex c2(7, 1);
    cout << (c1 += c2) << endl;
    cout << c1 + c2 << endl;
    cout << -c2 << endl;
    cout << IsConst(c1 += c2) << endl;
    cout << IsConst(c1 + c2) << endl;   // 临时对象都是const类型

    Complex* p = new Complex(3, 6);
    /* new的过程
    *  void* mem = operator new(sizeof(Complex)); // operator new内部调用malloc()
    *  Complex* p = static_cast<Complex*>(mem);
    *  p->Complex::Complex(3, 6);
    */
    cout << *p << endl;
    delete p;
    /* delete的过程
    *  Complex::~Complex(p);
    *  operator delete(p); // 内部调用free(p)
    */
    cout << sizeof(Complex) << endl;

    Complex c3;
    Complex* c4 = new Complex();
    cout << c3 << endl;
    cout << *c4 << endl;
    return 0;
}
