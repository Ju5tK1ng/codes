#include <bits/stdc++.h>
using namespace std;

struct size257
{
    char c[257];
};

int main()
{
    int a = 2;
    int& b = a;
    int* c = new int();
    *c = b;
    b = 3;
    cout << a << b << *c << endl;

    cout << sizeof(size257) << endl;
    deque<size257> dq;
    for (int i = 0; i < 40; i++)
    {
        size257 s;
        dq.push_back(s);
        cout << &dq.front() << "\t" << &dq.back() << endl;
        cout << i + 1 << "\t\t" << &dq.back() << endl;
    }
    size257 s;
    dq.push_front(s);
    // for (auto ite = dq.begin(); ite != dq.end(); ite++)
    // {
    //     cout << &*ite << endl;
    // }
    return 0;
}
