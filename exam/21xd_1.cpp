#include <bits/stdc++.h>
using namespace std;
char a[10010][10010];
class Solution {
private:
    int seed;
public:
    int simplerand()
    {
        seed = (seed * 1LL * 1103515245 + 12345) % (1LL << 31);
        return seed;
    }

    int generate(int seed, int R, int C, int wallCount, int torchCount, int monsterCount)
    {
        this->seed = seed;
        memset(a, '.', sizeof(a));
        for (int c = 0; c != wallCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            a[x][y] = 'W';
        }
        for (int c = 0; c != torchCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            if (a[x][y] == 'W')
            {
                continue;
            }
            a[x][y] = 'T';
            int t = x - 1;
            while (t >= 0 && a[t][y] != 'W' && a[t][y] != 'T')
            {
                a[t][y] = '*';
                t--;
            }
            t = x + 1;
            while (t < R && a[t][y] != 'W' && a[t][y] != 'T')
            {
                a[t][y] = '*';
                t++;
            }
            t = y - 1;
            while (t >= 0 && a[x][t] != 'W' && a[x][t] != 'T')
            {
                a[x][t] = '*';
                t--;
            }
            t = y + 1;
            while (t < C && a[x][t] != 'W' && a[x][t] != 'T')
            {
                a[x][t] = '*';
                t++;
            }
        }
        int ans = 0;
        for (int c = 0; c != monsterCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            if (a[x][y] == '.')
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution* s = new Solution();
    cout << s->generate(757147,5,5,1,1,10) << endl;
    cout << s->generate(180480072,5,5,4,1,12) << endl;
    cout << s->generate(160567225,5,5,3,1,6) << endl;
    cout << s->generate(1470545,5,5,2,0,5) << endl;
    return 0;
}
