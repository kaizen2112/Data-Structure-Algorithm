#include <bits/stdc++.h>
using namespace std;

const int n = 1e3;
vector<pair<int, int>> graph[n + 1];
vector<int> vis(n, 0);
vector<int> mstNodes;
vector<pair<int, int>> mstEdges; // To store edges in the MST
int cost;

int prims(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        // add it to mst
        vis[node] = 1;
        mstNodes.push_back(node);
        cost += wt;

        for (auto it : graph[node])
        {
            int adjnode = it.first;
            int weight = it.second;

            if (!vis[adjnode])
            {
                pq.push({weight, adjnode});
                mstEdges.push_back({min(node, adjnode), max(node, adjnode)});
            }
        }
    }
    return cost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    int src=1;

    cout <<  prims(src) << endl;




    return 0;
}
/*
3 3
1 2 5
2 3 3
1 3 1
1
*/
