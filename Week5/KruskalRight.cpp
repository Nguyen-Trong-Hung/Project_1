#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MaxN = 1 + 1e5;

class Edge {
    public:
        int u, v, w;

        Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}

        bool operator < (const Edge &op) const {
            return w < op.w;
        }
};

int n, m, parent[MaxN];
vector<Edge> edges;

void make_set(int u){
    parent[u] = u;
}

int find_set(int u){
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    for(int i = 1 ; i <= n ; ++i) make_set(i);
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(int i = 0 ; i < m ; ++i){
        Edge e = edges[i];
        int u = find_set(e.u);
        int v = find_set(e.v);
        if(u != v){
            ans += e.w;
            parent[u] = v;
        }
    }
    cout << ans << endl;

    return 0;
}
