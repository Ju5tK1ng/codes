#include<bits/stdc++.h>
using namespace std; 
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0), ans;
    for (auto& prerequisite : prerequisites)
    {
        graph[prerequisite[1]].push_back(prerequisite[0]);
        indegree[prerequisite[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int& num : graph[t])
        {
            indegree[num]--;
            if (indegree[num] == 0)
            {
                q.push(num);
            }
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] > 0)
        {
            return vector<int>();
        }
    }
    return ans;
}