#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For iota
using namespace std;

struct Edge {
    int u, v, cost;
    // Comparator to sort edges by cost
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// Find function for Union-Find
int Find(int u, vector<int>& parent) {
    if (parent[u] == -1) return u;
    return parent[u] = Find(parent[u], parent);
}

// Union function for Union-Find
void Union(int u, int v, vector<int>& parent) {
    int parentU = Find(u, parent);
    int parentV = Find(v, parent);
    if (parentU != parentV) {
        parent[parentU] = parentV;
    }
}

// Kruskal's Algorithm
double Kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end()); // Step 1: Sort edges by weight
    vector<int> parent(n + 1, -1);    // Initialize Union-Find parent array
    double mincost = 0.0;
    int i = 0; // Counter for edges in MST

    for (const auto& edge : edges) {
        if (i == n - 1) break; // MST completed
        int uSet = Find(edge.u, parent);
        int vSet = Find(edge.v, parent);

        if (uSet != vSet) { // Edge does not create a cycle
            i++;
            mincost += edge.cost;
            Union(uSet, vSet, parent);
        }
    }

    if (i != n - 1) {
        cout << "No spanning tree" << endl;
        return -1;
    }

    return mincost;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter the edges (u, v, cost):" << endl;
    for (int i = 0; i < e; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    double result = Kruskal(edges, n);
    if (result != -1) {
        cout << "Minimum Cost of Spanning Tree: " << result << endl;
    }

    return 0;
}

