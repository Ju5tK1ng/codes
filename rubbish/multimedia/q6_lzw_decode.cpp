#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> codes;
    vector<string> dictionary;
    int step = 0;
    int codes_size;
    int dict_size;
    cout << "Please input the size of codes: ";
    cin >> codes_size;
    for (int i = 0; i < codes_size; i++)
    {
        int code;
        cin >> code;
        codes.push_back(code);
    }
    cout << "Please input the size of initialized dictionary: ";
    cin >> dict_size;
    cout << "Please input the words in the initialized dictionary: " << endl;
    cout << "step   codes   dictionary   output" << endl;
    for (int i = 0; i < dict_size; i++)
    {
        string c;
        printf("                 (%d) ", i + 1);
        cin >> c;
        dictionary.push_back(c);
    }
    int c = codes[0] - 1;
    printf(" %-6d (1)      --  --      %s\n", ++step, dictionary[c].c_str());
    int p = c;
    for (int i = 1; i < codes.size(); i++)
    {
        c = codes[i] - 1;
        if (c < dictionary.size())
        {
            dictionary.push_back(dictionary[p] + dictionary[c][0]);
            printf(" %-6d (%d)      (%d) %-7s %s\n", ++step, codes[i], dictionary.size(), (dictionary[p] + dictionary[c][0]).c_str(), dictionary[c].c_str());
        }
        else
        {
            dictionary.push_back(dictionary[p] + dictionary[p][0]);
            printf(" %-6d (%d)      (%d) %-7s %s\n", ++step, codes[i], dictionary.size(), (dictionary[p] + dictionary[p][0]).c_str(), dictionary[c].c_str());
        }
        p = c;
    }
    return 0;
}