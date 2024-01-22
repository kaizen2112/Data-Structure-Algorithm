#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
}

bool bellmanFord(vector<vector<pair<int, int>>> &adj, int start, vector<int> &distance, vector<int> &predecessor)
{
    int V = adj.size();
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
                    predecessor[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    int cycle, c = -1;
    for (int u = 0; u < V; ++u)
    {
        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] != INF && distance[u] + weight < distance[v])
            {
                cycle = v;
                c = u;
                break;
            }
        }
        if (cycle != -1)
            break;
    }

    if (cycle != -1)
    {
        stack<int> loop;
        int node = c;
        loop.push(node);
        node = predecessor[node];
        while (node != c)
        {
            loop.push(node);
            node = predecessor[node];
        }
        loop.push(node);

        cout << "Negative Cycle: ";
        while (!loop.empty())
        {
            cout << loop.top() << "->";
            loop.pop();
        }
        cout << endl;

        return true; // Found a negative cycle
    }

    return false; // No negative cycle found
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

    vector<int> distance(V, INF);
    vector<int> predecessor(V, -1);

    if (!bellmanFord(adj, source, distance, predecessor))
    {
        cout << "No negative cycle found." << endl;
    }

    for (int i = 0; i < V; ++i)
    {
        for (auto &neighbor : adj[i])
        {
            neighbor.second = -neighbor.second;
        }
    }

    if (!bellmanFord(adj, source, distance, predecessor))
    {
        cout << "No positive cycle found." << endl;
    }

    return 0;
}
