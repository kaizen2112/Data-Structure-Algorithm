#include<bits/stdc++.h>
using namespace std;
int cost[5];                                                // 5 ta node
const int inf = 100000;                                     // infinity node
int visited[5] = {0};                                       // visited or not

void addEdge(int adj[][5], int x,int y, int cost)           // creating graph by adding edge
{
    adj[x][y] = cost;
    adj[y][x] = cost;
}

void bfs(int adj[][5], int start)
{
    cost[start] = 0;
    for(int j=0; j<5;j++)
    {
        int mcost = 1000;
        for(int k=0; k<5; k++)
        {
            if(visited[k] != 1 && cost[k] < mcost)
            {
                mcost = cost[k];
                start = k;
            }
        }
        for(int i=0; i<5; i++){
            if(adj[start][i] != inf){
                adj[start][i] =
                if(cost[i] > cost [start] + adj[start][i]){
                    cost[i] = cost [start] + adj[start][i];
                }
            }
        }
        visited[start] = 1;
    }
}

int main()
{
    const int v = 5;
    int adj[v][v];

    for(int i=0; i<v; i++)
    {
        cost[i] = inf;
        for(int j=0; j<v; j++)
        {
            adj[i][j]=inf;
        }
        cout<<endl;
    }

    addEdge(adj,0,1,10);
    addEdge(adj,0,2,20);
    addEdge(adj,1,2,12);
    addEdge(adj,2,4,16);

//    for(int i=0; i<v; i++)
//    {
//        for(int j=0; j<v; j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    bfs(adj, 0);
    for(int i = 0; i<5; i++){
        cout<<i<<" "<<cost[i]<<endl;
    }
}

