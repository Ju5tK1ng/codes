#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    unordered_map<string, int> dictionary;
    cout << "Please input string: ";
    cin >> input;
    cout << "output: ";
    for (int i = 0; i < input.size(); i++)
    {
        string c = input.substr(i, 1);
        if (!dictionary.count(c))
        {
            dictionary[c] = dictionary.size() + 1;
        }
    }
    string p = input.substr(0, 1);
    for (int i = 1; i < input.size(); i++)
    {
        string c = input.substr(i, 1);
        if (dictionary.count(p + c))
        {
            p = p + c;
        }
        else
        {
            dictionary[p + c] = dictionary.size() + 1;
            cout << dictionary[p];
            p = c;
        }
    }
    cout << dictionary[p] << endl;
    return 0;
}