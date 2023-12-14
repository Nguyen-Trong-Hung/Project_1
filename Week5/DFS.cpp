#include <bits/stdc++.h>

using namespace std;

vector<int> canhke[1001];

bool visited[1002];

void DFS(int u){
    cout << u <<" ";
    visited[u] = true;
    for(int x : canhke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        canhke[x].push_back(y);
        canhke[y].push_back(x);
    }

    for(int i = 1;i <= n;i++){
        cout << "Canh ke cua " << i << " : ";
        for(int x : canhke[i]){
            cout << x << " ";
        }
        cout << "\n";
    }

    DFS(1);
}