#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>>g[N];

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        
    }
}
    convert and rewrite this code where each node of graph contains two co ordinates and user will input any two nodes and the output will be the minimum cost of distance. all nodes are connected and the cost of distance for a node is the 2d distance from source node.
