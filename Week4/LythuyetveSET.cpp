#include <bits/stdc++.h>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long A[n];
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    set<int> s;
    for(int i = 0;i < n;i++){
        s.insert(A[i]);
    }
    cout << s.count(10);
}