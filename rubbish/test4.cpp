#include <bits/stdc++.h>
using namespace std;

struct A
{
    void Print()
    {
        cout << 1 << endl;
    }
};

struct B : public A
{
    void Print()
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
    return 0;
}
