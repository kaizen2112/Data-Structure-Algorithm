#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int x, int y, int weight)
{
    adj[x].push_back({y, weight});
    //adj[y].push_back({x, weight});
}

void dijkstra(vector<vector<pair<int, int>>> &adj, int start)
{
    int V = adj.size();
    vector<int> distance(V, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>> pq;    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int currDist = pq.top().second;
        int currNode = pq.top().first;
        pq.pop();

        if (currDist > distance[currNode])
            continue;

        for (auto neighbor : adj[currNode])
        {
            //cout<<currNode<<" "<<distance[currNode]<<" "<<neighbor.second<<" "<<distance[neighbor.first]<<endl;
            if(distance[currNode] + neighbor.second < distance[neighbor.first])        //int newDist = currDist + neighbor.second;
            {                                                                          //if (newDist < distance[neighbor.first])
                distance[neighbor.first] = distance[currNode] + neighbor.second;       //{
                                                                                       //   distance[neighbor.first] = newDist;
                pq.push({neighbor.first, distance[neighbor.first]});                   //    pq.push({newDist, neighbor.first});
            }                                                                          //}
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "Node " << i << ": " << distance[i] << "\n";
}

int main()
{
    int V, E; cin>>V>>E;
    vector<vector<pair<int, int>>> adj(V);

    int a, b, w;
    for(int i=0; i<E; i++)
    {
        cin>>a>>b>>w;
        addEdge(adj, a, b, w);
    }
    //addEdge(adj, 0, 1, 1);
    //addEdge(adj, 0, 2, 4);
    //addEdge(adj, 1, 3, 2);

    //cout << "Number of nodes: " << V << endl;
    int source;
    cin>>source;
    dijkstra(adj, source);

    return 0;
}
