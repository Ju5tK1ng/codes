#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        cout << i << ": " << v.size() << " " << v.max_size() << " " << v.capacity() << endl;
    }
    for (int i = 99; i >= 50; i--)
    {
        v.pop_back();
        cout << i << ": " << v.size() << " " << v.max_size() << " " << v.capacity() << endl;
    }
    for (int i = 49; i >= 0; i--)
    {
        v.resize(i);
        cout << i << ": " << v.size() << " " << v.max_size() << " " << v.capacity() << endl;
    }
    for (int i = 0; i < 150; i++)
    {
        v.reserve(i);
        cout << i << ": " << v.size() << " " << v.max_size() << " " << v.capacity() << endl;
    }
    v.resize(200);
    cout << 200 << ": " << v.size() << " " << v.max_size() << " " << v.capacity() << endl;
    v.resize(150);
    vector<int> v2(v);
    cout << 150 << ": " << v2.size() << " " << v2.max_size() << " " << v2.capacity() << endl;
    return 0;
}