#include<bits/stdc++.h>

using namespace std;

int x[10000];
int n;

void solution(){
    for(int i = 1;i <= n;i++){
        cout << x[i];
    }
    cout << endl;
}

bool check(int v,int k){
    return true;
}

void Try(int k){
    for(int v = 0;v <= 1;v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n)  solution();
            else    Try(k+1);
        }
    }
}

int main(){
    cin >> n;
    Try(1);
}
