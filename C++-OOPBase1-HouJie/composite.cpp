#include<bits/stdc++.h>
using namespace std;

#ifndef __COMPONENT__
#define __COMPONENT__

class Component
{
private:
    string name;
public:
    Component(string _name) : name(_name) {}
    virtual ~Component() {}
    string GetName()
    {
        return name;
    }
    void SetName(string _name)
    {
        name = _name;
    }
    void Print()
    {
        cout << name << endl;
    }
};

#endif


#ifndef __COMPOSITE__
#define __COMPOSITE__

class Composite : public Component
{
private:
    vector<Component*> componentList;
public:
    Composite(string _name) : Component(_name) {}
    virtual void Add(Component* c)
    {
        componentList.push_back(c);
        c->SetName(GetName() + c->GetName());
    }
};

#endif


#ifndef __PRIMITIVE__
#define __PRIMITIVE__

class Primitive : public Component
{
public:
    Primitive(string _name) : Component(_name) {}
};

#endif


int main()
{
    Composite* c1 = new Composite("C:\\");
    Composite* c2 = new Composite("Document\\");
    Primitive* p1 = new Primitive("File1");
    Primitive* p2 = new Primitive("File2");
    Primitive* p3 = new Primitive("File3");
    Primitive* p4 = new Primitive("File4");
    c1->Add(c2);
    c1->Add(p1);
    c1->Add(p2);
    c2->Add(p3);
    c2->Add(p4);
    c1->Print();
    c2->Print();
    p1->Print();
    p2->Print();
    p3->Print();
    p4->Print();
    return 0;
}
