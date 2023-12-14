#include <bits/stdc++.h>
#include<set>

using namespace std;

int main(){
    int n,M,Q;
    cin >> n >> M;
    int a[n];
    set<int> s;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        int k = M - a[i];
        if(s.count(k))  Q++;
        s.insert(a[i]);
    }
    cout << Q;
}