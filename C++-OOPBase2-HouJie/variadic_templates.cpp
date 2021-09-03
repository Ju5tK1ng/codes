#include <bits/stdc++.h>
using namespace std;

void Print()
{

}

template<typename T, typename... Types>
void Print(const T& arg, const Types&... args)
{
    cout << arg << endl;
    Print(args...);
}

int main()
{
    Print(123, "abc", 9.9, bitset<8>(123));
    return 0;
}
