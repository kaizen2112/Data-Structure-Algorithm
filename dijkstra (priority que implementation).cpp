#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9;

vector<pair<int, double>> g[N]; // int = node connected with
                                // double = weight
vector<int> dist(N, INF);

void dijkstra(int source)
{
    vector<int> vis(N, 0);
    //vector<int> dist(N, INF);
    priority_queue<pair<int, double>> st; // double = weight
                                          //  int = kon node er weight

    st.push({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = st.top();
        int v = node.second;
        int v_dist = node.first;
        st.pop();
        // if (vis[v])
        //     continue;
        // vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;

            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.push({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int ver, edg;
    cin>>ver>>edg;
    for (int i = 0; i < edg; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        g[x].push_back({y, wt});
    }

    int source;
    cin>>source;
    dijkstra(source);

    for (int i = 1; i <= ver; i++)
    {
        cout << "Shortest distance from " << source << " to " << i << " is: " << dist[i] << endl;
    }

    return 0;
}
