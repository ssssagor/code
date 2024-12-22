#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// Type alias for better readability
typedef pair<int, int> Edge; // {weight, node}

// Function to perform Prim's Algorithm
void primMST(int V, vector<vector<Edge>>& adj) {
    // Priority queue to pick the smallest edge weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Vector to check if a node is included in the MST
    vector<bool> inMST(V, false);

    // Vector to store the minimum weight edge to include a node
    vector<int> minEdgeWeight(V, INT_MAX);

    // Starting from node 0
    pq.push({0, 0}); // {weight, node}
    minEdgeWeight[0] = 0;

    int mstCost = 0; // To store the total cost of the MST

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        // If the node is already in MST, skip it
        if (inMST[u]) continue;

        // Include the node in MST
        inMST[u] = true;
        mstCost += weight;

        // Traverse all adjacent nodes
        for (auto& [w, v] : adj[u]) {
            if (!inMST[v] && w < minEdgeWeight[v]) {
                minEdgeWeight[v] = w;
                pq.push({w, v});
            }
        }
    }

    // Output the total cost of MST
    cout << "Total cost of MST: " << mstCost << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> adj(V);

    // Example edges of a graph: {u, v, weight}
    vector<tuple<int, int, int>> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    // Build the adjacency list
    for (auto [u, v, weight] : edges) {
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u});
    }

    // Run Prim's Algorithm
    primMST(V, adj);

    return 0;
}
