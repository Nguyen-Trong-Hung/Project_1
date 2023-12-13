#include <bits/stdc++.h>

using namespace std;

int x[10000];
int m[10000];
int n;

void solution(){
    for(int i = 1;i <= n;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for(int v = 1;v <= n;v++){
        if(!m[v]){
            x[k] = v;
            m[v] = true;
            if(k == n)  solution();
            else Try(k+1);
            m[v] = false;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
}
