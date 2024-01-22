#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
}

void bellmanFord(vector<vector<pair<int, int>>> &adj, int start)
{
    int V = adj.size();
    vector<int> distance(V, INF);
    distance[start] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i)
    {
        for (int u = 0; u < V; ++u)
        {
            for (auto neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distance[u] != INF && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u)
    {
        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] != INF && distance[u] + weight < distance[v])
            {
                cout << "Graph contains negative-weight cycle" << endl;
                return;
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Node " << i << ": " << distance[i] << "\n";
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);

    int a, b, w;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        addEdge(adj, a, b, w);
    }

    int source;
    cin >> source;
    bellmanFord(adj, source);

    return 0;
}
