#include<bits/stdc++.h>
using namespace std;

#ifndef __IOBSERVER__
#define __IOBSERVER__

class IObersever
{
public:
    virtual void Update() = 0;
    virtual ~IObersever() {}
};

#endif


#ifndef __SUBJECT__
#define __SUBJECT__

class Subject
{
private:
    vector<IObersever*> iOberseverList;

public:
    void AddObserver(IObersever* iObserver)
    {
        iOberseverList.push_back(iObserver);
    }

    void DoSth()
    {
        // xxx;
        Notify();
    }

    void Notify()
    {
        for (auto iobserver : iOberseverList)
        {
            iobserver->Update();
        }
    }
};

#endif


#ifndef __OBSERVER__
#define __OBSERVER__

class Observer : public IObersever
{
private:
    int order;

public:
    Observer(int _order) : order(_order) {}
    virtual void Update()
    {
        cout << "Update: " << order << endl;
    }
};

#endif

int main()
{
    Subject s;
    for (int i = 0; i < 4; i++)
    {
        Observer* o = new Observer(i);
        s.AddObserver(o);
    }
    s.DoSth();
    return 0;
}
