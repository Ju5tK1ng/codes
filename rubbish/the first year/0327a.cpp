#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    unsigned long long n;
    double ca = (1 + sqrt(5)) / 2;
    double cb = (1 - sqrt(5)) / 2;
    double cc = sqrt(5) / 5;
    double v1 = 0;
    double v2 = 0;
    cout <<" ";
    cin>>n;
    if(n > 0)
    {
        for (unsigned long long i = 0; i < n; i++)
    {
            v1 = cc * (pow(ca, i) - pow(cb, i));
        v2 = (int)v1;
        cout <<v2<<endl;
    }
    return 0;
    }
    else
    {
        return -1;
    }
        cout <<'/b';
}
