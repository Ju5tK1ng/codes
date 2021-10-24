#include <bits/stdc++.h>
using namespace std;

vector<int> d = {-1, 0, 1, 0, -1};

struct Point
{
    int x, y;

    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (const Point& r) const
    {
        if (x == r.x)
        {
            return y < r.y;
        }
        return x < r.x;
        // if (y == r.y)
        // {
        //     return x < r.x;
        // }
        // return y > r.y;
    }

    bool operator == (const Point& r) const
    {
        return x == r.x && y == r.y;
    }

    bool operator != (const Point& r) const
    {
        return !(*this == r);
    }
};

struct Priority
{
    Point p;
    int m, d;

    Priority() {}
    Priority(Point _p, int _m, int _d) : p(_p), m(_m), d(_d) {}

    bool operator < (const Priority& r) const
    {
        if (m == r.m)
        {
            return d < r.d;
        }
        return m < r.m;
    }

    bool operator > (const Priority& r) const
    {
        if (m == r.m)
        {
            return d > r.d;
        }
        return m > r.m;
    }
};

void plot(vector<vector<int>>& m, int cnt)
{
    cout << "cnt: " << cnt << endl;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            j == 14 ? printf("%3d\n", m[i][j]) : printf("%3d ", m[i][j]);
        }
    }
}

void bfs(vector<vector<int>> m, Point start, Point goal)
{
    int cnt = 0;
    queue<Point> q;
    q.push(start);
    map<Point, Point> from;
    from[start] = Point(-1, -1);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        if (cur == goal)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            Point next = Point(cur.x + d[i], cur.y + d[i + 1]);
            if (next.x >= 0 && next.x < 15 && next.y >= 0 && next.y < 15 && m[next.x][next.y] == -1)
            {
                m[next.x][next.y] = m[cur.x][cur.y] + 1;
                q.push(next);
                from[next] = cur;
                cnt++;
            }
        }
    }
    Point cur = goal;
    while (cur != start)
    {
        m[cur.x][cur.y] *= -1;
        cur = from[cur];
    }
    plot(m, cnt);
}

int manhattan(const Point& next, const Point& goal)
{
    return abs(next.x - goal.x) + abs(next.y - goal.y);
}

int distance(const Point& next, const Point& goal)
{
    return (next.x - goal.x) * (next.x - goal.x) + (next.y - goal.y) * (next.y - goal.y);
}

void gbfs(vector<vector<int>> m, Point start, Point goal)
{
    int cnt = 0;
    priority_queue<Priority, vector<Priority>, greater<Priority>> pq;
    pq.push(Priority(start, manhattan(start, goal), distance(start, goal)));
    map<Point, Point> from;
    from[start] = Point(-1, -1);
    while (!pq.empty())
    {
        Point cur = pq.top().p;
        pq.pop();
        if (cur == goal)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            Point next = Point(cur.x + d[i], cur.y + d[i + 1]);
            if (next.x >= 0 && next.x < 15 && next.y >= 0 && next.y < 15 && m[next.x][next.y] == -1)
            {
                m[next.x][next.y] = m[cur.x][cur.y] + 1;
                Priority priority = Priority(next, manhattan(next, goal), distance(next, goal));
                pq.push(priority);
                from[next] = cur;
                cnt++;
            }
        }
    }
    Point cur = goal;
    while (cur != start)
    {
        // cout << 2;
        m[cur.x][cur.y] *= -1;
        cur = from[cur];
    }
    plot(m, cnt);
}

void a_star(vector<vector<int>> m, Point start, Point goal)
{
    int cnt = 0;
    priority_queue<Priority, vector<Priority>, greater<Priority>> pq;
    pq.push(Priority(start, manhattan(start, goal), distance(start, goal)));
    map<Point, Point> from;
    from[start] = Point(-1, -1);
    map<Point, int> cost;
    cost[start] = 0;
    while (!pq.empty())
    {
        Point cur = pq.top().p;
        pq.pop();
        if (cur == goal)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            Point next = Point(cur.x + d[i], cur.y + d[i + 1]);
            int new_cost = cost[cur] + 1;
            if (next.x >= 0 && next.x < 15 && next.y >= 0 && next.y < 15 && (m[next.x][next.y] == -1 || new_cost < cost[next]))
            {
                m[next.x][next.y] = m[cur.x][cur.y] + 1;
                cost[next] = new_cost;
                Priority priority = Priority(next, new_cost + manhattan(next, goal), distance(next, goal));
                pq.push(priority);
                from[next] = cur;
                cnt++;
            }
        }
    }
    Point cur = goal;
    while (cur != start)
    {
        m[cur.x][cur.y] *= -1;
        cur = from[cur];
    }
    plot(m, cnt);
}

int main()
{
    vector<vector<int>> matrix =
    {
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  99, 99, 99, 99, 99,  99, 99, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},

        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},

        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, 99, -1, -1},
        { 0, -1, 99, 99, 99,  99, 99, 99, 99, 99,  99, 99, 99, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1},
    };
    Point start(12, 0), goal(1, 11);
    bfs(matrix, start, goal);
    gbfs(matrix, start, goal);
    a_star(matrix, start, goal);
    return 0;
}
