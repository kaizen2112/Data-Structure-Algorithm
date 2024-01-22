#include<bits/stdc++.h>
using namespace std;
/*
void addEdge(vector<vector<int>> &adj, int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}*/

void bfs(vector<vector<int>> &adj, int start)
{

    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q[0];
        cout << vis << " ";
        q.erase(q.begin());

        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v, e, a, b, start;
    cin>>v>>e;
    vector<vector<int>> adj(v,vector<int>(v,0));

    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    cin>>start;

    cout<<adj.size()<<endl;

    cout << "BFS traversal starting from node " << start << ": ";
    bfs(adj, start);
}
