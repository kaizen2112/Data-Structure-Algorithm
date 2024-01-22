#include <bits/stdc++.h>
using namespace std;

const int N  = 1e3;
vector<int>graph[N+1];
vector<int>vis(N,0);

// Time Complexity = O(V+E)
void dfs(int vertex)
{
    //Take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    cout<< vertex <<" ";
    vis[vertex]=1;
    for(auto child : graph[vertex])
    {
        //cout<<"Parent = " << vertex <<", Child = " << child <<endl;
        if(vis[child]==1) continue;
        //Take action on child befor entering the child node
        dfs(child);
        //Take action on child after exiting the child node
    }
    //Take action on vertex before exiting the vertex
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin>>source;

    dfs(source);
    
    return 0;
}

/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
1
*/
