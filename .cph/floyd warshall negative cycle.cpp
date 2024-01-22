#include <bits/stdc++.h>
using namespace std;
const int N = 300;
const int INF = INT_MAX;
int main()
{
    int v, e;
    cin >> v >> e;
    int dist[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 1; i <= e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        dist[a][b] = wt;
    }
    /*for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            if(dist[i][j]==INT_MAX) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            for (int k = 1; k <= v; k++)
            {
                if ((dist[k][i] + dist[i][j]) < dist[i][j])
                    dist[i][j] = dist[k][i] + dist[i][j];
            }
        }
    }
    cout << "Negative Cycle: ";
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i == j)
            {
                if (dist[i][j] < 0)
                    cout << i << " ";
            }
        }
        // cout<<endl;
    }

    return 0;
}
