#include <iostream>
using namespace std;

#ifndef __SMART_PTR__
#define __SMART_PTR__

template<class T>
class smart_ptr
{
private:
    T* px;
public:
    smart_ptr(T* p) : px(p) {}
    T& operator * () const
    {
        return *px;
    }
    T* operator -> () const
    {
        return px;
    }
};

#endif


struct Test
{
private:
    int a;
public:
    Test(int _a) : a(_a) {}
    void Print()
    {
        cout << a << endl;
    }
};

int main()
{
    smart_ptr<Test> sp(new Test(2));
    (*sp).Print();
    sp->Print();
    return 0;
}
