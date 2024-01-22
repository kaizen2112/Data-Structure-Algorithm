#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
    adj[y].push_back({x, weight});
}

void dijkstra(vector<vector<pair<int, int>>> &adj, int start)
{
    int V = adj.size();
    vector<int> distance(V, INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > distance[currNode])
            continue;

        for (auto neighbor : adj[currNode])
        {
            if(distance[currNode] + neighbor.second < distance[neighbor.first])        //int newDist = currDist + neighbor.second;
            {                                                                          //if (newDist < distance[neighbor.first])
                distance[neighbor.first] = distance[currNode] + neighbor.second;       //{
                                                                                       //   distance[neighbor.first] = newDist;
                pq.push({distance[neighbor.first], neighbor.first});                   //    pq.push({newDist, neighbor.first});
            }                                                                          //}
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Node " << i << ": " << distance[i] << "\n";
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 3, 2);

    cout << "Number of nodes: " << V << endl;

    dijkstra(adj, 0);

    return 0;
}
