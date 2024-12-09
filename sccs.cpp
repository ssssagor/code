#include <bits/stdc++.h>

using namespace std;



void DFS1(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            DFS1(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}
void DFS2(int node, vector<int> transposedAdj[], vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : transposedAdj[node])
    {
        if (!visited[neighbor])
        {
            DFS2(neighbor, transposedAdj, visited, component);
        }
    }
}
void findSCCs(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS1(i, adj, visited, st);
        }
    }
    vector<int> transposedAdj[V];
    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            transposedAdj[neighbor].push_back(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components are:\n";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            vector<int> component;
            DFS2(node, transposedAdj, visited, component);
            for (int v : component)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    findSCCs(V, adj);
    return 0;
}
