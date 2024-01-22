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

    for (int i = 0; i < V - 1; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            for (auto neighbor : adj[j])
            {
                int u = j;
                int v = neighbor.first;
                int w = neighbor.second;

                if (distance[u] != INF && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // Check for negative cycles in an extra iteration
    for (int j = 0; j < V; ++j)
    {
        for (auto neighbor : adj[j])
        {
            int u = j;
            int v = neighbor.first;
            int w = neighbor.second;

            if (distance[u] != INF && distance[u] + w < distance[v])
            {
                cout<< "Negative cycle detected" ;
                return;
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Node " << i << ": " << distance[i] << "\n";

    //return; // No negative cycle found
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);

    int a, b, w;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        addEdge(adj, a, b, w);
    }

    int source;
    cin >> source;

    bellmanFord(adj, source);

    return 0;
}
