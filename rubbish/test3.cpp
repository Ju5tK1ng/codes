#include <bits/stdc++.h>
using namespace std;
struct A
{
    int a;
    char b;
    char c;
};

struct B
{
    int a;
    char b;
    int c;
};

struct C
{
    int a;
    long long b;
    long long c;
};

struct D
{
    int a;
    long long b;
    int c;
};

struct  E
{
    long long a;
    char b;
    char c;
};

struct  F
{
    char a;
    long long b;
    char c;
};

struct G
{
    char a;
    short b;
    char c;
};


int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    cout << sizeof(F) << endl;
    cout << sizeof(G) << endl;
    return 0;
}