#include<bits/stdc++.h>
using namespace std;
const int infinity= 1e9;
const int N = 100;
int adj[N][N];
void floydwarshall(int v)
{
    //floyd warshall
    for(int k=1; k<=v ;k++)
    {
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(adj[i][j]>adj[i][k] + adj [k][j])
                adj[i][j] = adj[i][k] + adj [k][j] ;
            }
        }
    }
    for(int i=1 ; i<=v ; i++)
    {
        for(int j=1; j<= v ; j++ )
        {
            if(adj[i] [j]==infinity)
            cout<<"X"<<" ";
            else
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int v, e ;
    cin >> v >> e ;
    for(int i=0;i<N;i++)
    {
        for(int j=0 ; j < N ;j++)
        {
            if(i==j) adj[i][j]=0;
            else
            adj[i][j]=infinity;
        }
    }
    for(int i =0;i<e;i++)
    {
        int x,y,w;
        cin >> x >> y >> w ;
        adj[x][y]=w;
    }

    floydwarshall(v);

}
