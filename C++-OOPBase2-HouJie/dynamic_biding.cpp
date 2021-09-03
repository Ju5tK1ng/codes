#include <iostream>
using namespace std;

#ifndef __BASE__
#define __BASE__

class Base
{
public:
    virtual void Print()
    {
        cout << "Base" << endl;
    }
};

#endif


#ifndef __DERIVED__
#define __DERIVED__

class Derived : public Base
{
    virtual void Print()
    {
        cout << "Derived" << endl;
    }
};

#endif


int main()
{
    Derived stack_d;
    Base stack_b = (Base)stack_d;
    stack_b.Print();

    Base* heap1_b = &stack_d;
    heap1_b->Print();

    Base* heap2_b = new Derived();
    heap2_b->Print();

    Derived* heap_d = new Derived();
    Base* heap3_b = (Base*)heap_d;
    heap3_b->Print();

    return 0;
}
