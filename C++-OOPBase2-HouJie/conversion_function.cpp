#include <iostream>
using namespace std;

#ifndef __FRACTION__
#define __FRACTION__

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction (int num, int den = 1) : numerator(num), denominator(den) {}
    operator double() const
    {
        return (double)numerator / denominator;
    }
};

#endif


int main()
{
    Fraction* f1 = new Fraction(3, 5);
    cout << 1 + *f1 << endl;
    return 0;
}
