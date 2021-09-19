#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int seed;
    int R;
    int C;
    unordered_map<int, set<int>> walls;
    unordered_map<int, set<int>> wallsC;
    unordered_map<int, set<int>> TR;
    unordered_map<int, set<int>> TC;
public:
    int simplerand()
    {
        seed = (seed * 1LL * 1103515245 + 12345) % (1LL << 31);
        return seed;
    }

    int generate(int seed, int R, int C, int wallCount, int torchCount, int monsterCount)
    {
        this->seed = seed;
        this->R = R;
        this->C = C;
        walls.clear();
        wallsC.clear();
        TR.clear();
        TC.clear();
        for (int c = 0; c != wallCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            walls[x].insert(y);
            wallsC[y].insert(x);
            cout << x << " " << y << endl;
        }
        for (int c = 0; c != torchCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            if (walls.count(x) && walls[x].count(y))
            {
                continue;
            }
            TR[x].insert(y);
            TC[y].insert(x);
            cout << x << " " << y << endl;
        }
        int ans = 0;
        for (int c = 0; c != monsterCount; c++)
        {
            int x = simplerand() % R;
            int y = simplerand() % C;
            if (walls.count(x) && walls[x].count(y))
            {
                continue;
            }
            if (ok(x, y))
            {
                ans++;
            }
        }
        return ans;
    }

    bool ok(int x, int y)
    {
        if (TR.count(x))
        {
            if (!walls.count(x) || TR[x].count(y))
            {
                return false;
            }
            else
            {
                auto iteT1 = upper_bound(TR[x].begin(), TR[x].end(), y);
                auto iteW1 = upper_bound(walls[x].begin(), walls[x].end(), y);
                if (iteT1 != TR[x].end() && (iteW1 == walls[x].end() || *iteT1 < *iteW1))
                {
                    return false;
                }
                if (iteT1 != TR[x].begin() && (iteW1 == walls[x].begin() || *--iteT1 > *--iteW1))
                {
                    return false;
                }
            }
        }
        if (TC.count(y))
        {
            if (!wallsC.count(y) || TC[y].count(x))
            {
                return false;
            }
            else
            {
                auto iteT1 = upper_bound(TC[y].begin(), TC[y].end(), x);
                auto iteW1 = upper_bound(wallsC[y].begin(), wallsC[y].end(), x);
                if (iteT1 != TC[y].end() && (iteW1 == wallsC[y].end() || *iteT1 < *iteW1))
                {
                    return false;
                }
                if (iteT1 != TC[y].begin() && (iteW1 == wallsC[y].begin() || *--iteT1 > *--iteW1))
                {
                    return false;
                }
            }
        }
        cout << x << " " << y << endl;
        return true;
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
