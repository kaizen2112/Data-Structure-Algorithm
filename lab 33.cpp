#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, cost;
    Edge(int aa, int bb, int costt) {
        this->a = aa;
        this->b = bb;
        this->cost = costt;
    }
};

int n, m, v;
vector<Edge> edges;
const int INF = 1000000000;

void BellmanFord() {
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF) {
                    cout<<d[e.b]<<" "<< d[e.a]<< " "<<e.cost<<endl;
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                    cout<<i<<" "<<x<<endl;

                }
            }
        }
    }

    if (x == -1)
        cout << "No negative cycle" << endl;
    else {
        vector<int> negativeCycle;
        vector<int> positiveCycle;

        int y = x;
       // do {
         //   y = p[y];
           // y++;
        //} while (y != x);

        int current = y;
        negativeCycle.push_back(current);
        do {
            current = p[current];
            negativeCycle.push_back(current);
        } while (current != y);
        reverse(negativeCycle.begin(), negativeCycle.end());

        for (int node : negativeCycle) {
            cout << node << " ";
        }
        cout << endl;

    }
}

int main() {
    cin >> n >> m;
    edges.clear();

    for (int i = 0; i < m; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back(Edge(a, b, cost));
    }
    cout<<edges.size();
    v = 0;
    BellmanFord();

    return 0;
}




