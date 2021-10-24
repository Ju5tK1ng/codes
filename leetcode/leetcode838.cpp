#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = -1, r = INT_MIN, ans = 0;
        for (int i = 0; i < dominoes.size(); i++)
        {
            if (dominoes[i] == '.')
            {
                if (r > l)
                {
                    dominoes[i] = 'R';
                }
            }
            else if (dominoes[i] == 'L')
            {
                if (r < l)
                {
                    for (int j = l + 1; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                }
                if (r > l)
                {
                    for (int j = r + (i - r) / 2 + 1; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                    if ((i - r) % 2 == 0)
                    {

                        dominoes[r + (i - r) / 2] = '.';
                    }
                }
                l = i;
            }
            else
            {
                r = i;
            }
        }
        if (r > l)
        {
            for (int i = r + 1; i < dominoes.size(); i++)
            {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
