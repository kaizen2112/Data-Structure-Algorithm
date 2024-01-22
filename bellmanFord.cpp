#include <bits/stdc++.h>
using namespace std;

const int N=1e3;
const int INF=1e9;

vector<vector<int>>graph;


void bellmanford(int src, int n)
{
    vector<int>dist(n,INF);
    dist[src]=0;
    for(int i=0; i<n-1; i++)
    {
        for(auto e:graph)
        {
            int u=e[0];
            int v=e[1];
            int wt=e[2];

             if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (auto i : dist)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        graph.push_back({u,v,wt});
    }
    int src;
    cin>>src;
    bellmanford(src,n);
    
    return 0;
}
/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/
