#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 1;i <= T;i++){
        int n,m;
        vector<int> adj[1001];
        cin >> n >> m;
        for(int i = 0;i < m;i++){
                int x,y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }

        int hamilton = n/2;
        int count = 0;
        for(int i = 1;i <= n;i++){
            int tmp = adj[i].size();
            if(tmp >= hamilton)
                count++;
        }

        if(count == n)  cout << "1" << "\n";
        else    cout << "0" << "\n";
    }
}
