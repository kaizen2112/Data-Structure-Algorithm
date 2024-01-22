#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

class Point {
public:
    int x, y;
};

vector<vector<pair<int, int>>> adj;

double distance( Point &p1, Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void dijkstra(int s, vector<double> &d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<double, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        double d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Point> nodes(n);

    for (int i = 0; i < n; i++) {
        cin >> nodes[i].x >> nodes[i].y;
    }

    adj.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(nodes[i], nodes[j]);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    int source, target;
    cin >> source >> target;

    vector<double> d;
    vector<int> p;
    dijkstra(source, d, p);

    if (d[target] != INF) {
        cout << "Minimum cost of distance: " << d[target] << endl;
    }

    return 0;
}
