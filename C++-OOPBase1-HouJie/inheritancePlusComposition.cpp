#include<iostream>
using namespace std;

#ifndef __BASE__
#define __BASE__

class Base
{
public:
    Base()
    {
        cout << "Base" << endl;
    }
    ~Base()
    {
        cout << "~Base" << endl;
    }
};

#endif


#ifndef __COMPONENT__
#define __COMPONENT__

class Component
{
public:
    Component()
    {
        cout << "Component" << endl;
    }
    ~Component()
    {
        cout << "~Component" << endl;
    }
};

#endif


#ifndef __DERIVED__
#define __DERIVED__

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived" << endl;
    }
    ~Derived()
    {
        cout << "~Derived" << endl;
    }

private:
    Component component;
};

#endif

int main()
{
    Derived d;
    return 0;
}
