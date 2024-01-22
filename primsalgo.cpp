#include<bits/stdc++.h>
using namespace std;
#define ss
#define ff
int graph[N][N];
int prim(int src)
{

    bool vis[n+1] ={false};
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({0,src});
    int counter=0;
    while(counter!=n)
    {
        pii p= pq.top();
        pq.pop();

        int u = p.ss;
        int ct= p.ff;

        if(!vis[u])
        {
            vis[u] = true;
            cost+=ct;
            counter++;
            for(auto v: adj[u])
            {
                if(!vis[v.ss])
                {
                    pq.push(v);
                }
            }
        }
    }
    return cost;
}
int main()
{
    int vertex, edge, weight;


}
complete this code for prims algorithm for finding minimum spanning tree
