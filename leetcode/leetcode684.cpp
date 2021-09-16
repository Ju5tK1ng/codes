#include <bits/stdc++.h>
using namespace std;
class UF
{
private:
    vector<int> id, size;
public:
    UF(int n) : id(n), size(n, 1)
    {
        iota(id.begin(), id.end(), 0);
    }

    int find(int p)
    {
        if (p == id[p])
        {
            return p;
        }
        return id[p] = find(id[p]);
    }

    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i != j)
        {
            if (size[i] < size[j])
            {
                id[i] = j;
                size[j] += size[i];
            }
            else
            {
                id[j] = i;
                size[i] += size[j];
            }
        }
        id[find(p)] = find(q);
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n + 1);
        for (auto& v : edges)
        {
            int x = v[0], y = v[1];
            if (uf.isConnected(x, y))
            {
                return v;
            }
            uf.connect(x, y);
        }
        return vector<int>{-1, -1};
    }
};
