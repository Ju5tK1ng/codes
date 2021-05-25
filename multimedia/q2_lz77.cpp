#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input = "AABCBBABC";
    string match;
    int window_size = 0;
    int step = 0;
    cout << "step   position   match string   char   output" << endl;
    for (int i = 0; i < input.size(); i++)
    {
        int pointer = 0, length = 0;
        for (int j = 0; j < window_size; j++)
        {
            int t = 0;
            while (i + t < input.size() && j + t < window_size && input[i + t] == input[j + t])
            {
                t++;
            }
            if (t > length)
            {
                pointer = i - j; // pointer指下标偏移量，不是指下标
                length = t;
            }
        }
        match = length > 0 ? input.substr(i, length) : "--";
        printf(" %-8d %-11d %-11s %-5c (%d, %d) %c\n", ++step, i + 1, match.c_str(), input[i + length], pointer, length, input[i + length]);
        i += length;
        window_size += length + 1;
    }
    return 0;
}