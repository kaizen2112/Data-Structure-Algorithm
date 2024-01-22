#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> parent;
vector<int> dist; // Rename the distance vector

void addEdge(int x, int y, int weight)
{
    adj[x].push_back({y, weight});
    //adj[y].push_back({x, weight});
}

void dijkstra(int start)
{
    int V = adj.size();
    dist.assign(V, INF); // Initialize the dist vector
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int currDist = pq.top().second;
        int currNode = pq.top().first;
        pq.pop();

        if (currDist > dist[currNode])
            continue;

        for (auto neighbor : adj[currNode])
        {
            if( dist[neighbor.first] > dist[currNode] + neighbor.second)
            {
                dist[neighbor.first] = dist[currNode] + neighbor.second;
                pq.push({neighbor.first, dist[neighbor.first]});

                parent[neighbor.first].first = currNode;
                parent[neighbor.first].second = dist[neighbor.first];
            }
        }
    }
}

void printPath(int start, int end) {
    if (start == end) {
        cout << start;
        return;
    }
    printPath(start, parent[end].first);
    cout << " -> " << end;
}

void printDistance(int end) {
    cout << endl << "Distance: " << parent[end].second;
}

int main()
{
    int V, E;
    cin >> V >> E;
    adj.resize(V);
    parent.resize(V, make_pair(-1, 0));

    int a, b, w;
    for(int i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        addEdge(a, b, w);
    }

    int source, destination;
    cin >> source >> destination;
    dijkstra(source);

    printPath(source, destination);

    printDistance(destination);

    return 0;
}
