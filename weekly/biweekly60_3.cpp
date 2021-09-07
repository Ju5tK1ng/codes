#include <bits/stdc++.h>
using namespace std;

// // 1.0
// class LockingTree {
// private:
//     struct Tree
//     {
//         int parent;
//         unordered_set<int> sonLockSet;
//         int lock;
//     }tree[2010];
// public:
//     LockingTree(vector<int>& parent)
//     {
//         int l = parent.size();
//         for (int i = 0; i < l; i++)
//         {
//             tree[i].parent = parent[i];
//             tree[i].lock = 0;
//         }
//     }

//     bool lock(int num, int user)
//     {
//         if (tree[num].lock == 0)
//         {
//             tree[num].lock = user;
//             int parent = tree[num].parent;
//             while (parent != -1)
//             {
//                 tree[parent].sonLockSet.insert(num);
//                 parent = tree[parent].parent;
//             }
//             return true;
//         }
//         return false;
//     }

//     bool unlock(int num, int user)
//     {
//         if (tree[num].lock == user)
//         {
//             tree[num].lock = 0;
//             int parent = tree[num].parent;
//             while (parent != -1)
//             {
//                 tree[parent].sonLockSet.erase(num);
//                 parent = tree[parent].parent;
//             }
//             return true;
//         }
//         return false;
//     }

//     bool upgrade(int num, int user)
//     {
//         if (tree[num].lock == 0 && !tree[num].sonLockSet.empty())
//         {
//             int parent = tree[num].parent;
//             while (parent != -1)
//             {
//                 if (tree[parent].lock != 0)
//                 {
//                     return false;
//                 }
//                 parent = tree[parent].parent;
//             }
//             lock(num, user);
//             unordered_set<int> t(tree[num].sonLockSet);
//             for (int son : t)
//             {
//                 unlock(son, tree[son].lock);
//             }
//             return true;
//         }
//         return false;
//     }
// };

// 2.0
int locked[2010];
int pa[2010];
vector<int> sons[2010];
bool found;
class LockingTree
{
public:
    LockingTree(vector<int>& parent)
    {
        for (int i = 0; i < parent.size(); i++)
        {
            pa[i] = parent[i];
            sons[i].clear();
        }
        for (int i = 1; i < parent.size(); i++)
        {
            sons[parent[i]].push_back(i);
        }
        memset(locked, 0, sizeof(locked));
    }

    bool lock(int num, int user)
    {
        if (locked[num] == 0)
        {
            locked[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user)
    {
        if (locked[num] == user)
        {
            locked[num] = 0;
            return true;
        }
        return false;
    }

    // // 2.0
    // bool upgrade(int num, int user)
    // {
    //     if (locked[num] != 0)
    //     {
    //         return false;
    //     }
    //     int parent = pa[num];
    //     while (parent != -1)
    //     {
    //         if (locked[parent] != 0)
    //         {
    //             return false;
    //         }
    //         parent = pa[parent];
    //     }
    //     found = false;
    //     queue<int> qson;
    //     for (int son : sons[num])
    //     {
    //         qson.push(son);
    //     }
    //     while (!qson.empty())
    //     {
    //         int s = qson.front();
    //         qson.pop();
    //         if (found)
    //         {
    //             locked[s] = 0;
    //         }
    //         else if (locked[s] != 0)
    //         {
    //             found = true;
    //             locked[s] = 0;
    //         }
    //         for (int son : sons[s])
    //         {
    //             qson.push(son);
    //         }
    //     }
    //     if (found)
    //     {
    //         locked[num] = user;
    //     }
    //     return found;
    // }

    // 2.1
    bool upgrade(int num, int user)
    {
        if (dfs1(num))
        {
            return false;
        }
        found = false;
        dfs2(num);
        if (found)
        {
            dfs3(num);
            locked[num] = user;
        };
        return found;
    }

    bool dfs1(int num)
    {
        if (num == -1)
        {
            return false;
        }
        if (locked[num] != 0)
        {
            return true;
        }
        return dfs1(pa[num]);
    }

    void dfs2(int num)
    {
        for (int son : sons[num])
        {
            if (locked[son] != 0)
            {
                found = true;
                break;
            }
            dfs2(son);
        }
    }

    void dfs3(int num)
    {
        locked[num] = 0;
        for (int son : sons[num])
        {
            dfs3(son);
        }
    }
};
