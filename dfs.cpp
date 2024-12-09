#include <bits/stdc++.h>

using namespace std;

// Global variables
map<int, vector<int>> adjacencyList; // Adjacency list to store the graph
map<int, int> discoveryTime;         // Discovery time of each vertex
map<int, int> finishTime;            // Finish time of each vertex
map<int, int> parent;                // Parent of each vertex
map<int, string> color;              // Color of each vertex: "WHITE", "GRAY", "BLACK"
int currentTime = 0;                 // Keeps track of the time

// Function to perform DFS-Visit
void DFSVisit(int vertex) {
    currentTime++;
    discoveryTime[vertex] = currentTime;
    color[vertex] = "GRAY";

    for (int neighbor : adjacencyList[vertex]) {
        if (color[neighbor] == "WHITE") {
            parent[neighbor] = vertex;
            DFSVisit(neighbor);
        }
    }

    color[vertex] = "BLACK";
    currentTime++;
    finishTime[vertex] = currentTime;
}

// Function to perform DFS
void DFS() {
    for (auto& pair : adjacencyList) {
        int vertex = pair.first;
        color[vertex] = "WHITE";
        parent[vertex] = -1;
    }

    currentTime = 0;

    for (auto& pair : adjacencyList) {
        int vertex = pair.first;
        if (color[vertex] == "WHITE") {
            DFSVisit(vertex);
        }
    }
}

// Main function
int main() {
    // Adding edges to the graph (example graph)
    adjacencyList[1] = {2, 3};
    adjacencyList[2] = {4};
    adjacencyList[3] = {4};
    adjacencyList[4] = {};

    // Perform DFS
    DFS();

    // Print the results
    cout << "Vertex\tDiscovery\tFinish\tParent\n";
    for (auto& pair : adjacencyList) {
        int vertex = pair.first;
        cout << vertex << "\t" << discoveryTime[vertex] << "\t\t"
             << finishTime[vertex] << "\t" << parent[vertex] << "\n";
    }

    return 0;
}
