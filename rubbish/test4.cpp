#include <bits/stdc++.h>
using namespace std;

struct A
{
    virtual void Print()
    {
        cout << 1 << endl;
    }
};

struct B : public A
{
    virtual void Print()
    {
        cout << 2 << endl;
    }
};

struct C : public A
{

};

int main()
{
    B b;
    C c;
    b.Print();
    c.Print();
    B* d = new B();
    A* a = (A*)d;
    a->Print();
    a->A::Print();
    return 0;
}
