#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> capacity;

// Hàm BFS tìm đường tăng cung
bool BFS(int s, int t, vector<int>& parent, vector<int>& minCapacity) {
    fill(parent.begin(), parent.end(), -1);
    fill(minCapacity.begin(), minCapacity.end(), 0);
    parent[s] = s;
    minCapacity[s] = INF;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                minCapacity[v] = min(minCapacity[u], capacity[u][v]);
                if (v == t) {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}

int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(N);
    vector<int> minCapacity(N);
    while (BFS(s, t, parent, minCapacity)) {
        int pathFlow = minCapacity[t];
        flow += pathFlow;
        int v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
            v = u;
        }
    }
    return flow;
}

int main() {
    cin >> N >> M;
    int s, t;
    cin >> s >> t;
    graph.resize(N);
    capacity = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        capacity[u - 1][v - 1] += c;
    }

    int maxFlowValue = maxFlow(s - 1, t - 1);
    cout << maxFlowValue << endl;

    return 0;
}
