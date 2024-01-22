#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
    adj[y].push_back({x, weight}); // Add this line for undirected graph
}

pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>> &adj, int start)
{
    int V = adj.size();
    vector<int> distance(V, INF);
    vector<int> parent(V, -1); // To store the parent of each node in the shortest path
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currDist = -pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currDist > distance[currNode])
            continue;

        for (auto neighbor : adj[currNode])
        {
            int newDist = currDist + neighbor.second;
            if (newDist < distance[neighbor.first])
            {
                distance[neighbor.first] = newDist;
                parent[neighbor.first] = currNode;
                pq.push({-newDist, neighbor.first});
            }
        }
    }

    return make_pair(distance, parent);
}

vector<int> getPath(int destination, const vector<int> &parent)
{
    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    return path;
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

    int source, destination;
    cin >> source >> destination;

    pair<vector<int>, vector<int>> result = dijkstra(adj, source);
    vector<int> distance = result.first;
    vector<int> parent = result.second;

    if (distance[destination] == INF)
    {
        cout << "No path exists between nodes " << source << " and " << destination << endl;
    }
    else
    {
        cout << "Shortest path between nodes " << source << " and " << destination << ":\n";

        vector<int> shortestPath = getPath(destination, parent);
        for (int node : shortestPath)
        {
            cout << node << " ";
        }
        cout << "\nTotal distance: " << distance[destination] << endl;
    }

    return 0;
}
