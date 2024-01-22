#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
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
int main(){

    int n;
    cin>>n;

    vector<pair<int,int>>pt(n);

    adj.resize(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pt[i] = {x,y};
    }


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d = abs(pt[i].first - pt[j].first) +
                    abs(pt[i].second - pt[j].second);

            adj[i].push_back({j,d});
            adj[j].push_back({i,d});
        }
    }

    int sx,sy;

    int dx,dy;

    cin>>sx>>sy>>dx>>dy;

    int s;
    int t;

    for(int i=0;i<n;i++){
        if(pt[i].first==sx and pt[i].second==sy) s = i;
        if(pt[i].first==dx and pt[i].second==dy) t = i;
    }
    vector<int>d,p;

    dijkstra(s,d,p);

    cout<<d[t]<<endl;
}
