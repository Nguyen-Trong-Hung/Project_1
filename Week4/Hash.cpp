#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m, r[201];
    string s[1000];
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    r[0] = 1;
    for(int i = 1; i<=200;i++){
        r[i] = 256*r[i-1];
        r[i]%=m;
    }
    
    for (int i = 0; i < n; i++) {
        int hash_code = 0;
        int k = s[i].length();
        for (int j = 0; j < k; j++) {
            hash_code += s[i][j]*r[k-j-1];
            hash_code %= m;
        }
        cout << hash_code << endl;
    }
}