#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adjMatrix, int start) {
    int n = adjMatrix.size();                                 // Number of nodes in the graph
    vector<bool> visited(n, false);                           // Keep track of visited nodes
    queue<int> q;                                             // Queue for BFS traversal

    q.push(start);                                            // Start BFS from the given node
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";                                // Process the current node

        for (int neighbor = 0; neighbor < n; ++neighbor) {     // Visit all adjacent nodes of the current node using the adjacency matrix
            if (adjMatrix[current][neighbor] && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;                                                  // Number of nodes and edges
    cin >> n >> m;

     vector<vector<int>> adjMatrix(n, vector<int>(n, 0));      // Create an adjacency matrix representation of the graph

     for (int i = 0; i < m; ++i) {                              // Read the edges of the graph and populate the adjacency matrix
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;                                    // adjMatrix[v][u] = 1;  // Uncomment this line for an undirected graph
    }

    int startNode;  // Node to start BFS from
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(adjMatrix, startNode);

    return 0;
}
