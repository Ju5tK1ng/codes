#include <bits/stdc++.h>
using namespace std;

class UF
{
private:
    vector<int> id;
public:
    UF(int n) : id(n)
    {
        for (int i = 0; i < id.size(); i++)
        {
            id[i] = i;
        }
    }

    int find(int p)
    {
        if (id[p] == p)
        {
            return p;
        }
        return id[p] = find(id[p]);
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }

    void connect(int p, int q)
    {
        id[find(p)] = find(q);
    }
};

int main()
{
    int n, a, m, p, q;
    char c;
    cin >> n >> a >> m;
    UF uf(n);
    unordered_set<int> us;
    us.insert(a);
    while (m--)
    {
        cin >> p >> c >> q;
        uf.connect(p, q);
        if (p == a)
        {
            us.insert(q);
        }
        if (q == a)
        {
            us.insert(p);
        }
    }
    int old = us.size();
    for (int i = 0; i < n; i++)
    {
        if (uf.isConnected(a, i))
        {
            us.insert(i);
        }
    }
    cout << us.size() - old << endl;
    return 0;
}
