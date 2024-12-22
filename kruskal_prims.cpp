#include<bits/stdc++.h>
#include <chrono> // For timing
using namespace std;
using namespace chrono;

// Structure to represent an edge for Kruskal's Algorithm
struct Edge
{
    char u, v; // Vertices as symbols
    int weight;
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

// Function to remove parallel edges and retain only the smallest weight edge
vector<Edge> removeParallelEdges(const vector<Edge>& edges)
{
    map<pair<char, char>, int> edgeMap;

    // Store the smallest weight for each pair of vertices
    for (size_t i = 0; i < edges.size(); ++i)
    {
        char u = min(edges[i].u, edges[i].v); // Ensure consistent ordering
        char v = max(edges[i].u, edges[i].v);
        if (edgeMap.find(make_pair(u, v)) == edgeMap.end() || edges[i].weight < edgeMap[make_pair(u, v)])
        {
            edgeMap[make_pair(u, v)] = edges[i].weight;
        }
    }

    // Recreate the edges vector with unique edges
    vector<Edge> uniqueEdges;
    for (map<pair<char, char>, int>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it)
    {
        uniqueEdges.push_back({it->first.first, it->first.second, it->second});
    }

    return uniqueEdges;
}

// Kruskal's Algorithm
int kruskalMST(const vector<char>& vertices, vector<Edge>& edges)
{
    unordered_map<char, int> symbolToIndex;
    int V = vertices.size();
    for (int i = 0; i < V; i++)
    {
        symbolToIndex[vertices[i]] = i;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Union-Find (Disjoint Set Union)
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) parent[i] = i;

    int mstCost = 0;
    vector<Edge> mstEdges;

    for (size_t i = 0; i < edges.size(); ++i)
    {
        int u = symbolToIndex[edges[i].u];
        int v = symbolToIndex[edges[i].v];

        int rootU = u;
        while (parent[rootU] != rootU) rootU = parent[rootU];
        int rootV = v;
        while (parent[rootV] != rootV) rootV = parent[rootV];

        if (rootU != rootV)
        {
            mstCost += edges[i].weight;
            mstEdges.push_back(edges[i]);
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // Print MST edges
    cout << "Kruskal's MST edges:\n";
    for (size_t i = 0; i < mstEdges.size(); ++i)
    {
        cout << mstEdges[i].u << " -- " << mstEdges[i].v << " == " << mstEdges[i].weight << endl;
    }

    return mstCost;
}

// Prim's Algorithm
int primMST(const vector<char>& vertices, vector<vector<pair<char, int>>>& adj)
{
    unordered_map<char, int> symbolToIndex;
    int V = vertices.size();
    for (int i = 0; i < V; i++)
    {
        symbolToIndex[vertices[i]] = i;
    }

    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    // Start with vertex 0
    key[0] = 0;
    pq.push(make_pair(0, vertices[0])); // {weight, vertex}

    int mstCost = 0;

    while (!pq.empty())
    {
        pair<int, char> top = pq.top();
        char uSymbol = top.second;
        int u = symbolToIndex[uSymbol];
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstCost += key[u];

        for (size_t i = 0; i < adj[u].size(); ++i)
        {
            char vSymbol = adj[u][i].first;
            int weight = adj[u][i].second;
            int v = symbolToIndex[vSymbol];
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push(make_pair(key[v], vSymbol));
                parent[v] = u;
            }
        }
    }

    // Print MST edges
    cout << "Prim's MST edges:\n";
    for (int v = 1; v < V; ++v)
    {
        if (parent[v] != -1)
        {
            cout << vertices[parent[v]] << " -- " << vertices[v] << " == " << key[v] << endl;
        }
    }

    return mstCost;
}

int main()
{
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E'}; // Vertices as symbols

    // Input graph with parallel edges
    vector<Edge> edges =
    {
        {'A', 'B', 2}, {'A', 'B', 3}, {'A', 'D', 6}, {'B', 'C', 3},
        {'B', 'C', 2}, {'B', 'D', 8}, {'B', 'E', 5}, {'C', 'E', 7},
        {'D', 'E', 9}, {'D', 'E', 4}
    };

    // Remove parallel edges
    edges = removeParallelEdges(edges);

    // Prepare adjacency list for Prim's Algorithm
    vector<vector<pair<char, int>>> adj(vertices.size());
    unordered_map<char, int> symbolToIndex;
    for (int i = 0; i < vertices.size(); i++)
    {
        symbolToIndex[vertices[i]] = i;
    }
    for (size_t i = 0; i < edges.size(); ++i)
    {
        int u = symbolToIndex[edges[i].u];
        int v = symbolToIndex[edges[i].v];
        adj[u].push_back(make_pair(edges[i].v, edges[i].weight));
        adj[v].push_back(make_pair(edges[i].u, edges[i].weight));
    }

    // Measure time for Kruskal's Algorithm
    high_resolution_clock::time_point startKruskal = high_resolution_clock::now();
    cout << "Running Kruskal's Algorithm:\n";
    int kruskalCost = kruskalMST(vertices, edges);
    high_resolution_clock::time_point endKruskal = high_resolution_clock::now();
    long long kruskalDuration = duration_cast<microseconds>(endKruskal - startKruskal).count();
    cout << "Total cost of Kruskal's MST: " << kruskalCost << "\n";
    cout << "Kruskal's Algorithm Execution Time: " << kruskalDuration << " microseconds\n\n";

    // Measure time for Prim's Algorithm
    high_resolution_clock::time_point startPrim = high_resolution_clock::now();
    cout << "Running Prim's Algorithm:\n";
    int primCost = primMST(vertices, adj);
    high_resolution_clock::time_point endPrim = high_resolution_clock::now();
    long long primDuration = duration_cast<microseconds>(endPrim - startPrim).count();
    cout << "Total cost of Prim's MST: " << primCost << "\n";
    cout << "Prim's Algorithm Execution Time: " << primDuration << " microseconds\n";

    return 0;
}
