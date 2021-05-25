#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input = "ABBCBCABA";
    unordered_map<string, int> dictionary = {{"", 0}};
    string p;
    int step = 0;
    cout << "step   position   dictionary   output" << endl;
    for (int i = 0; i < input.size(); i++)
    {
        string c = input.substr(i, 1);
        if (dictionary.count(p + c))
        {
            p = p + c;
        }
        else
        {
            dictionary[p + c] = dictionary.size();
            printf(" %-8d %-11d %-8s (%d, %c)\n", ++step, i + 1 - p.size(), (p + c).c_str(), dictionary[p], input[i]);
            p = "";
        }
    }
    return 0;
}