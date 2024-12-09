#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adj)
{
    vector<int> inDegree(n, 0);
    vector<int> topoOrder;
    queue<int> q;


    for (int i = 0; i < n; i++)
    {
        for (int v : adj[i])
        {
            inDegree[v]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }


    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }


    if (topoOrder.size() != n)
    {
        cout << "The graph has a cycle, topological sort not possible." << endl;
        return {};
    }

    return topoOrder;
}

int main()
{
    int n = 7;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {2,5};
    adj[2] = {3};
    adj[3] = {};
    adj[4] = {};
    adj[5] = {3,4};
    adj[6] = {1,5};


    vector<int> topoOrder = topologicalSort(n, adj);



    cout << "A valid topological order is: ";
    for (int node : topoOrder)
    {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}
