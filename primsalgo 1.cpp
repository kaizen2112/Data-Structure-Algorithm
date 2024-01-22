#include<bits/stdc++.h>
using namespace std;

const int N = 1005; // Update N to the maximum number of vertices
typedef pair<int, int> pii;

int graph[N][N];
bool vis[N]; // Mark visited vertices
vector<pii> adj[N];
int n;

int prim(int src) {
    int cost = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();

        int u = p.second;
        int ct = p.first;

        if (!vis[u]) {
            vis[u] = true;
            cost += ct;

            for (auto v : adj[u]) {
                int weight = v.first;
                int vertex = v.second;
                if (!vis[vertex]) {
                    pq.push({weight, vertex});
                }
            }
        }
    }

    return cost;
}

int main() {
    int vertex, edge, weight;
    cin >> n >> edge; // Read number of vertices and edges

    for (int i = 0; i < edge; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Read edge (u, v) with weight w
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u); // Assuming the graph is undirected
    }

    int minimumCost = prim(1); // Assuming starting vertex is 1
    cout << "Minimum Cost of Spanning Tree: " << minimumCost << endl;

    return 0;
}
