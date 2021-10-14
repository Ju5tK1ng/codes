#include<bits/stdc++.h>
using namespace std;

#ifndef __Singleton__
#define __Singleton__

// 局部静态变量版本，c++11后线程安全
class Singleton
{
private:
    int num;
    Singleton(int _num = 1) : num(_num) {}

public:
    static Singleton& GetInstance();
    void Print()
    {
        cout << num << endl;
    }
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
