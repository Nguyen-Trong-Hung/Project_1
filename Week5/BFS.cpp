#include <bits/stdc++.h>

using namespace std;

int n,m;
set<int> adj[1001];
bool visited[1001];

void input(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    memset(visited,false,sizeof(visited));
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main(){
    input();
    for(int i = 1;i <= n;i++){
        if(!visited[i])
            BFS(i);
    }
}