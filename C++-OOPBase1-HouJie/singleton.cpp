#include<bits/stdc++.h>
using namespace std;

#ifndef __Singleton__
#define __Singleton__

class Singleton
{
public:
    static Singleton& GetInstance();
    void Print()
    {
        cout << num << endl;
    }

private:
    int num;
    Singleton(int _num = 1) : num(_num) {}

};

Singleton& Singleton::GetInstance()
{
    static Singleton instance;
    return instance;
}

#endif

int main()
{
    Singleton::GetInstance().Print();
    return 0;
}
