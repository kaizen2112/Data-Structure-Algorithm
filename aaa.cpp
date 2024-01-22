#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
                                                //int n = graph.size();  // Number of nodes in the graph
    vector<bool> visited(graph.size(), false);  // Keep track of visited nodes
    queue<int> q;                               // Queue for BFS traversal

    q.push(start);                              // Start BFS from the given node
    visited[start] = true;

    int current;
    while (!q.empty()) {
        current = q.front();
        cout << current << " ";                 // Process the current node
        q.pop();

        for (int neighbor : graph[current]) {                        // Visit all adjacent nodes of the current node
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;                                          // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int>> graph(n);                      // Create an adjacency list representation of the graph

        for (int i = 0; i < m; ++i) {                  // Read the edges of the graph
          int u, v;
          cin >> u >> v;
          graph[u].push_back(v);                       // graph[v].push_back(u);
        }
    int startNode;
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(graph, startNode);

    return 0;
}
