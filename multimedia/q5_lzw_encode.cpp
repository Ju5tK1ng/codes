#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    unordered_map<string, int> dictionary;
    int step = 0;
    cout << "Please input the string: ";
    cin >> input;
    cout << "step   position   dictionary   output" << endl;
    for (int i = 0; i < input.size(); i++)
    {
        string c = input.substr(i, 1);
        if (!dictionary.count(c))
        {
            dictionary[c] = dictionary.size() + 1;
            printf("                    (%d) %s\n", dictionary[c], c.c_str());
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
            printf(" %-8d %-9d (%d) %-7s (%d)\n", ++step, i + 1 - p.size(), dictionary[p + c], (p + c).c_str(), dictionary[p]);
            p = c;
        }
    }
    printf(" %-8d --        --  --      (%d)\n", ++step, dictionary[p]);
    return 0;
}