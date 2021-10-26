#include <bits/stdc++.h>
using namespace std;

struct Base
{
    void (*func)();
    int b;
};

struct Derived
{
    Base base;
    int d;
};

void Base_func()
{
    printf("Base_func()\n");
}

void Derived_func()
{
    printf("Derived_func()\n");
}

int main()
{
    Base b;
    Derived d;
    b.func = Base_func;
    d.base.func = Derived_func;
    Base* p = &b;
    p->func();
    p = (Base*)&d;
    p->func();
    return 0;
}
