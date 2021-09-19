#include <bits/stdc++.h>
using namespace std;
class DetectSquares {
private:
    map<int, map<int, int>> m;
public:
    DetectSquares() {
        m.clear();
    }

    void add(vector<int> point) {
        m[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int cnt = 0, x = point[0], y = point[1];
        for (auto& p : m[x])
        {
            int l = abs(p.first - y);
            if (l == 0)
            {
                continue;
            }
            if (m.count(x - l) && m[x - l].count(p.first) && m[x - l].count(y))
            {
                cnt += m[x][p.first] * m[x - l][p.first] * m[x - l][y];
            }
            if (m.count(x + l) && m[x + l].count(p.first) && m[x + l].count(y))
            {
                cnt += m[x][p.first] * m[x + l][p.first] * m[x + l][y];
            }
        }
        return cnt;
    }
};
