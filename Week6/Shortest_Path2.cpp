#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;
const ll INF = numeric_limits<ll>::max();

struct Edge {
    int to;
    ll weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    vector<ll> dist(n, INF);
    dist[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        ll u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u]) continue;

        for (const Edge& e : adj[u]) {
            int v = e.to;
            ll w = e.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF)
        cout << -1 << endl;
    else
        cout << dist[t] << endl;

    return 0;
}
