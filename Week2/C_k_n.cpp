#include<bits/stdc++.h>
#define modulo 1000000007
const int MAX = 10000;
using namespace std;

int m[MAX][MAX];

int aftermod(int k,int n){
    if(k == 0 || k == n)
        m[k][n] = 1;
    else{
        if(m[k][n] == 0)
        m[k][n] = aftermod(k-1,n-1) + aftermod(k,n-1);
    }
    return m[k][n]%modulo;
}

int main(){    
    int k,n;
    cin >> k >> n;
    cout << aftermod(k,n);
}
