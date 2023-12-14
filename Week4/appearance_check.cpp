#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    long long A[n];
    long long B[n];
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(A[j] == A[i]){
                B[i] = 1;
                break;
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(B[i] != 1)   B[i] = 0;
        cout << B[i] << "\n";
    }
}