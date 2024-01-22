#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
    adj[y].push_back({x, weight}); // Add this line for undirected graph
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int start, int end)
{
    int V = adj.size();
    vector<int> distance(V, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currDist = pq.top().first; // Change here to use negative distance for min-heap
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
                pq.push({newDist, neighbor.first}); // Change here to use negative distance for min-heap
            }
        }
    }

    vector<int> shortestPath;
    if (distance[end] == INF)
        return shortestPath; // No path exists

    int current = end;
    while (current != start)
    {
        shortestPath.push_back(current);
        for (auto neighbor : adj[current])
        {
            if (distance[current] == distance[neighbor.first] + neighbor.second)
            {
                current = neighbor.first;
                break;
            }
        }
    }
    shortestPath.push_back(start);
    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
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

    vector<int> shortestPath = dijkstra(adj, source, destination);

    if (shortestPath.empty())
    {
        cout << "No path exists between nodes " << source << " and " << destination << endl;
    }
    else
    {
        cout << "Shortest path between nodes " << source << " and " << destination << ":\n";
        for (int node : shortestPath)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
