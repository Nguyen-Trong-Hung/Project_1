#include<bits/stdc++.h>
using namespace std;

const int MaxN = 100001;
const int INF = 1000000;

int n, m, s;
int dist[MaxN];
vector<pair<int, int>> adj[MaxN];

void Dijkstra(int s){
    fill(dist + 1, dist + n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int t;
    cin >> s >> t;
    Dijkstra(s);
    if(dist[t] == INF) 
        cout << -1 << endl;
    else
        cout << dist[t] << endl;
    return 0;
}