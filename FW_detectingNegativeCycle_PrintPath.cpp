#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9;

int dist[N][N];
int next_vertex[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        dist[u][v] = wt;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != INF && i != j)
                next_vertex[i][j] = j;
            else
                next_vertex[i][j] = -1;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_vertex[i][j] = next_vertex[i][k];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "Graph contains a negative cycle." << endl;

            vector<int> cycle;
            int start = i;
            cycle.push_back(start);

            int current = next_vertex[start][start];
            while (current != start)
            {
                cycle.push_back(current);
                current = next_vertex[current][start];
            }
            cycle.push_back(start);

            for (auto vertex : cycle)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    // No negative cycle found
    // cout << "Graph doesn't contain a negative cycle." << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (dist[i][j] == INF)
    //             cout << "-1 ";
    //         else
    //             cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
/*
8 9
1 2 -1
2 3 4
3 5 -6
5 2 -5
3 8 -6
8 4 3
4 6 -1
6 7 2
7 4 -5
*/