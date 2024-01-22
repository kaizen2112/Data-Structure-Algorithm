
#include<bits/stdc++.h>
using namespace std;

//vector<vector<int>> adj;

void addEdge(int adj[][5], int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int adj[][5], int start)
{

    vector<bool> visited(5, false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q[0];
        cout << vis << " ";
        q.erase(q.begin());

        for (int i = 0; i < 5; i++)
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
    const int v = 5;
    int adj[v][v];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);

    bfs(adj, 0);
}
---------------------------------------------------------


-----------Using 2D vector------------------------------

#include<bits/stdc++.h>
using namespace std;

//vector<vector<int>> adj;

void addEdge(vector<vector<int>> &adj, int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

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
    int v = 5;
    vector<vector<int>> adj(v,vector<int>(v,0));

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);

    cout<<adj.size()<<endl;

    bfs(adj, 0);
}
--------------------------------------------------

