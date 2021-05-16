#include<bits/stdc++.h>
using namespace std;
struct A
{
    int a;
};
struct B
{
    int b;
    B* next;
};
class C
{
    public:
        int val;
        C* next;
    ~C()
    {

    }
};
int main()
{
    A* a = new A();
    B* b = new B();
    C* c = new C();
    C* c2 = new C();
    cout << (c->next != nullptr) << endl;
    c->next = c2;
    memset(a, 1, sizeof(a));
    memset(b, 2, sizeof(b));
    memset(c2, 4, sizeof(c2));
    cout << (c->next != nullptr) << endl;
    cout << c->next->val << endl;
    memset(c, 3, sizeof(c));
    cout << (c->next != nullptr) << endl;
    cout << c->next->val << endl;
    cout << a->a << endl;
    cout << b->b << endl;
    cout << c->val << endl;
    return 0;
}