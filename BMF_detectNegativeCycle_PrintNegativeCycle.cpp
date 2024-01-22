#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9;

vector<vector<int>> graph;

void bellmanFord(int src, int n)
{
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    int cycle_start = -1;

    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (auto edge : graph)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    for (auto edge : graph)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            cycle_start = v;
            break;
        }
    }

    if (cycle_start != -1)
    {
        cout << "Graph contains a negative cycle." << endl;

        vector<int> cycle;
        vector<bool> visited(n, false);
        while (!visited[cycle_start])
        {
            cycle.push_back(cycle_start);
            visited[cycle_start] = true;
            cycle_start = parent[cycle_start];
        }

        for (int i = 0; i < cycle.size(); ++i)
        {
            if (cycle[i] == cycle_start)
            {
                cycle.erase(cycle.begin(), cycle.begin() + i);
                break;
            }
        }

        for (int vertex : cycle)
        {
            cout << vertex << " ";
        }
        cout << cycle_start << endl;
    }
    else
    {
        cout << "No negative cycle found." << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph.push_back({u, v, wt});
    }

    int source;
    cin >> source;

    bellmanFord(source, n);

    /*
    //Printing Positive Cycle
    for(int i=0; i<m; i++)
    {
        graph[i][2] *= -1;
    }

    bellmanFord(source,n);
    */

    


    return 0;
}

/*
7 8
0 1 1
1 2 -1
2 3 -2
3 1 -3
2 4 1
4 5 1
5 6 2
6 4 3
0
*/