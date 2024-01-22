#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);  // Keep track of visited nodes
    stack<int> st;                               // Stack for DFS traversal

    st.push(start);                              // Start DFS from the given node

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (!visited[current]) {
            cout << current << " ";  // Process the current node
            visited[current] = true;

            // Push unvisited neighbors onto the stack
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int>> graph(n);  // Create an adjacency list representation of the graph

    for (int i = 0; i < m; ++i) {  // Read the edges of the graph
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u); // Commented out because this is for directed graph
    }

    int startNode;
    cin >> startNode;

    cout << "DFS traversal starting from node " << startNode << ": ";
    dfs(graph, startNode);

    return 0;
}
