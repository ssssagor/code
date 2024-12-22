#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    char u, v; // Vertices represented as symbols
    int weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Function to remove parallel edges and keep the one with the minimum weight
vector<Edge> removeParallelEdges(const vector<Edge>& edges) {
    unordered_map<string, Edge> edgeMap;

    for (const auto& edge : edges) {
        string key = edge.u < edge.v ? string{edge.u, edge.v} : string{edge.v, edge.u};
        if (edgeMap.find(key) == edgeMap.end() || edge.weight < edgeMap[key].weight) {
            edgeMap[key] = edge; // Keep the edge with the smallest weight
        }
    }

    vector<Edge> filteredEdges;
    for (const auto& [key, edge] : edgeMap) {
        filteredEdges.push_back(edge);
    }

    return filteredEdges;
}

// Find function for Union-Find with path compression
int find(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = find(parent[node], parent); // Path compression
    }
    return parent[node];
}

// Union function for Union-Find with rank optimization
bool unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU == rootV) return false; // u and v are already in the same set

    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }

    return true;
}

// Kruskal's Algorithm
int kruskalMST(const vector<Edge>& edges, const vector<char>& vertices) {
    int V = vertices.size();
    vector<Edge> sortedEdges = removeParallelEdges(edges);

    // Sort edges by weight
    sort(sortedEdges.begin(), sortedEdges.end());

    // Map symbols to indices
    unordered_map<char, int> symbolToIndex;
    for (int i = 0; i < V; i++) {
        symbolToIndex[vertices[i]] = i;
    }

    // Initialize parent and rank arrays for Union-Find
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstCost = 0;
    vector<Edge> mstEdges;

    // Iterate through the sorted edges
    for (const auto& edge : sortedEdges) {
        int u = symbolToIndex[edge.u];
        int v = symbolToIndex[edge.v];
        if (unite(u, v, parent, rank)) {
            mstCost += edge.weight;
            mstEdges.push_back(edge);
        }
    }

    // Print the edges in the MST
    cout << "Edges in the MST:\n";
    for (const auto& edge : mstEdges) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }

    return mstCost;
}

int main() {
    // Vertices represented as symbols
    vector<char> vertices = {'A', 'B', 'C', 'D', 'E','F'};

    // Edges of the graph: {u, v, weight}
    vector<Edge> edges = {
        {'A', 'B', 5}, {'A', 'B', 6}, {'A', 'D', 4},{'A', 'C', 8}, {'A', 'E', 7}, {'B', 'F', 3}, {'B', 'F', 2},
        {'C', 'D', 2}, {'C', 'A', 8}, {'C', 'E', 3}, {'D', 'D', 2}, {'D', 'A', 4}, {'D', 'F', 3}, {'D', 'C', 2}, {'E', 'A', 7}, {'E', 'C', 3}, {'F', 'B', 3}, {'F', 'B', 2}, {'F', 'D', 3}
    };

    // Run Kruskal's Algorithm
    int mstCost = kruskalMST(edges, vertices);

    cout << "Total cost of MST: " << mstCost << endl;

    return 0;
}
